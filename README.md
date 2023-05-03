<h1>Meu simples servidor em C++.</h1> 

[<strong>Português-BR</strong>](#portuguese)  
[<strong>Inglish</strong>](#inglish) 

<br>

<div id="portuguese">
<h2>
    <u>
        Português-BR
    </u>
</h2><br>
<h3>Bem, eu estava dando uma mechida com sockets em Python, e estava querendo treinar um pouco de C++, então decide refazer um projeto básico meu em Python em C++, o projeto era basicamente um "Servidor de respostas anonimas", ele funciona assim:<br><br>  

- Um servidor UDP recebe a mensagem de um client e armazena-a e envia outra mensagem ao client, como forma de resposta.
- Quando outro client envia uma mensagem, o servidor envia a mensagem armazenada para o client e armazena a recebida.  
- Se repete o mesmo processo...<br><br>  

<h2>Imagens</h2>

```shell
##server:
cd server
compile.bat

## client:
cd client
compile.bat

##ou execute 1 por 1 dos comandos dentro do compile.bat
```

<h2>Imagens</h2>
<img src="images\client.png">
<img src="images\server.png">
</h3><br><br>

<div id="inglish">  
<h2>
    <u>
        Inglish
    </u>
</h2><br>
<h3>

Well, I was messing around with sockets in Python, and I wanted to practice some C++, so I decided to redo a basic project of mine in Python in C++, the project was basically an "Anonymous Response Server", it works like this:    
<u>Note</u>: Google translator was used, so I'm sorry if there are some spelling mistakes.<br><br>

- A UDP server receives a message from a client and stores it and sends another message to the client as a response.
- When another client sends a message, the server sends the stored message to the client and stores the received one.
- The process is repeated...<br><br>

<h2>Compile</h2>

```shell
##server:
cd server
compile.bat

## client:
cd client
compile.bat

## Or run 1 by 1 of the commands inside compile.bat
```

<h2>Images</h2>
<img src="images\client.png">
<img src="images\server.png">
</h3>

