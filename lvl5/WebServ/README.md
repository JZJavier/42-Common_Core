# WebServ

This project is here to make you write your own HTTP server. You will be able to test it with a real browser. HTTP is one of the most used protocol on internet. Knowing its arcane will be useful, even if you won't be working on a website.
##### This is when you finally understand why a URL starts with HTTP

## Requirements
• Your program has to take a configuration file as argument, or use a default path.

• You can’t execve another web server.

• Your server must never block and the client can be bounced properly if necessary.

• It must be non-blocking and use only 1 poll() (or equivalent) for all the I/O
operations between the client and the server (listen included).

• poll() (or equivalent) must check read and write at the same time.

• You must never do a read or a write operation without going through poll() (or
equivalent).

• Checking the value of errno is strictly forbidden after a read or a write operation.

• You don’t need to use poll() (or equivalent) before reading your configuration file.

• You can use every macro and define like FD_SET, FD_CLR, FD_ISSET, FD_ZERO (un-
derstanding what and how they do it is very useful).

• A request to your server should never hang forever.

• Your server must be compatible with the web browser of your choice.

• We will consider that NGINX is HTTP 1.1 compliant and may be used to compare
headers and answer behaviors.

• Your HTTP response status codes must be accurate.

• You server must have default error pages if none are provided.

• You can’t use fork for something else than CGI (like PHP, or Python, and so forth).

• You must be able to serve a fully static website.

• Clients must be able to upload files.

• You need at least GET, POST, and DELETE methods.

• Stress tests your server. It must stay available at all cost.

• Your server must be able to listen to multiple ports (see Configuration file)

## Bonus
• Support cookies and session management (prepare quick examples).
• Handle multiple CGI.

## Team Work
This project was carried out in collaboration with `Yuhong Gao` and `Pablo Palma` .
For further information about him and his work, please refer to the links provided.

-   [Linkedin Gao](https://www.linkedin.com/in/yuhong-g-71796925a/)
-   [GitHub Gao](https://github.com/Gabri177)

-   [Linkedin Pablo](https://www.linkedin.com/in/pablopalmarodr%C3%ADguez/)
-   [GitHub Pablo](https://github.com/Pablo-Palma)

## Grade
<p align="center">
<img width="210" alt="125" src="https://github.com/JZJavier/42/assets/76801285/9b5924a8-8876-4bce-b783-1e6b5da93252">
</p>
