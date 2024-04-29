#include "Routers.h"
#include "UserService.h"

UserService* userService = new UserService();

void route::RegisterResources(hv::HttpService& router)
{

    router.GET("/user", [](HttpRequest* req, HttpResponse* resp)
        {
            std::map<unsigned int, UserEntity*> users = userService->getAllUsers();

            nlohmann::json usersJson;

            for (const auto& pair : users) {
                usersJson[std::to_string(pair.first)] = pair.second->toString();
            }

            nlohmann::json response
            {
                {"users", usersJson}
            };

            resp->SetBody(response.dump());
            resp->content_type = APPLICATION_JSON;

            return 200;
        });

    router.GET("/user/{userId}", [](HttpRequest* req, HttpResponse* resp)
        {
            nlohmann::json response;

            unsigned int id;
            std::stringstream ss(req->GetParam("userId"));
            UserEntity* user = nullptr;

            if (ss >> id) {
                user = userService->getUser(id);
            }

            if (user != nullptr) {
                response["user"] = user->toString();
            }
            else {
                response["error"] = " Not found user with id=" + req->GetParam("userId");
                resp->SetBody(response.dump());
                resp->content_type = APPLICATION_JSON;
                return 400;
            }

            resp->SetBody(response.dump());
            resp->content_type = APPLICATION_JSON;

            return 200;
        });

    router.POST("/user", [](HttpRequest* req, HttpResponse* resp)
        {
            nlohmann::json request;
            nlohmann::json response;

            try
            {
                request = nlohmann::json::parse(req->body);
                UserEntity* user = new UserEntity(request["name"], (unsigned int)request["age"]);
                userService->addUser(user);
            }
            catch (const std::exception& e)
            {
                response["error"] = "Invalid JSON";
                resp->SetBody(response.dump());
                resp->content_type = APPLICATION_JSON;
                return 400;
            }

            resp->SetBody(request.dump());
            resp->content_type = APPLICATION_JSON;

            return 200;
        });

    router.Delete("/user/{userId}", [](HttpRequest* req, HttpResponse* resp)
        {
            nlohmann::json response;

            unsigned int id;
            std::stringstream ss(req->GetParam("userId"));
            bool isDeleted = false;

            if (ss >> id) {
                isDeleted = userService->deleteUser(id);
            }

            if (isDeleted) {
                response["status"] = "User with id = " + req->GetParam("userId") + " has been deleted!";
            }
            else {
                response["status"] = "User with id = " + req->GetParam("userId") + " has`t been deleted!";
                resp->SetBody(response.dump());
                resp->content_type = APPLICATION_JSON;
                return 400;
            }

            resp->SetBody(response.dump());
            resp->content_type = APPLICATION_JSON;

            return 200;
        });

}