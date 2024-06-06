*** bootstrap_chocolatine ***
TThe repository contains all project binaries that I have mentioned in my cover letter. In a brief description, I will describe how to test each of them.
NB: Always go to the repository before testing.

***ascii_runner repository***
It is simply a replica of the dino run game that we can see in network pbs cases in the Chrome browser, but in ncurses and with a human. I implemented it for another EPITECH challenge themed "Flame and Olympic Games". The goal is simply to tap space to jump over inflamed obstacles after compiling "run.c" with "gcc run.c && ./a.out".

***Jam repository***
It is the voice compiler that I implemented for a Tech Challenge. To test it, I advise you to connect a high-quality microphone to your laptop and go to a silent room to avoid disturbances or errors (no Bluetooth). Once finished, you can execute the python file "audio_text.py" and give one of these commands: "ls", "make re", "push in github", and "exit". The code simply takes your audio command and converts it into text. Once finished, the text will be submitted to an error margin that will enable identification of the correct command and its execution.

***todolist***
It was part of the epytodo project, and I had implemented a todo list backend composed of a database and many routes such as:

_____________________________________________________________________
|Routes            | Method | Protected | Description               |
|------------------|--------|-----------|---------------------------|
| /register        | POST   | no        | Register a new user       |
| /login           | POST   | no        | Connect a user            |
| /user            | GET    | yes       | View all user information |
| /user/todos      | GET    | yes       | View all user tasks       |
| /users/:id or :email | GET    | yes  | View user information      |
| /users/:id       | PUT    | yes       | Update user information   |
| /users/:id       | DELETE | yes       | Delete user               |
| /todos           | GET    | yes       | View all the todos        |
| /todos/:id       | GET    | yes       | View the todo             |
| /todos           | POST   | yes       | Create a todo             |
| /todos/:id       | PUT    | yes       | Update a todo             |
| /todos/:id       | DELETE | yes       | Delete a todo             |
---------------------------------------------------------------------

To test it, you can simply create your own "epytodo database" with the command "cat epytodo.sql | sudo mysql -u root", install packages with npm install if you have node.js, and "npm start" to launch the server. You are free to use the backend simulator of your choice (Postman, ThunderClient, etc.) to test all routes.

***n4s_package repository***
It is an experimental platform Elora that enables learning about AI development with lessons, challenges, and quizzes developed with SDL library in the C language. To execute it, you just have to launch the binary "./Elora". The case "Learn" to learn about AI development theoretically, the case "Quiz" to test theoretical competences, and "Manual" to explain how to use my application. The "Challenges" part should consist of submitting many AI challenges and problems such as "Implement an AI to automate a virtual car according to sensor information in Need4Speed Challenge, to fight a boss in my CSFML window based on the enemies' state and giving instructions; to play and win all sokoban maps regardless of the situation; . . . " that will enable the user to put his theoretical knowledge into practice.

***paint repository***
It is the "my_paint" project that consisted of implementing a graphical design interface in C with the CSFML library. Many options are available without the possibility to import pictures or to go to a new paper. Also, all files are saved with the name Akatsuka.png. To test it, you must type in the shell "clear && make re ; ./my_paint". Good inspiration :)

***other repository***
In this, it justifies my understanding of Docker, Github, and other technologies. For example, it contains examples of workflows, Dockerfiles, and docker-compose that I have used.

                                                                              _____     _   _   _  __      __  _______   _____  
                                                                             |_   _|   | | | | | |/ /     /_||__   __| / ____| 
                                                                               | |   __| | | | | ' / ______  _| | |     | (___   
                                                                               | |  |__  | | | |  < |______|| |  | |      \___ \  
                                                                              _| |_    | | | | | . \        | |  | |      ____) | 
                                                                             |_____|   |_| |_| |_|\_\       |_|  |_|     |_____/  


