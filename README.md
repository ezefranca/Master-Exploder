### Projeto Integrador III - [![Build Status](https://travis-ci.org/ezefranca/BCC-1s14-PI3-Master-Exploder.png?branch=master)](https://travis-ci.org/ezefranca/BCC-1s14-PI3-Master-Exploder)
===

#### Sobre o Projeto Integrador
---------------------
Projeto Integrador III, do Bacharelado em Ciência da Computação do Centro Universitário Senac - Campus São Paulo. 

O Projeto Integrador III, tem como objetivo o desenvolvimento de um jogo em linguagem C, utlizando a biblioteca Allegro 5, e sua iteração seja feira através de visão computacional.

Apesar de utilizar o OpenCV para aquisição das imagens, todo tratamento e algoritmos para processamento de imagens e reconhecimento de padrões foi feito em linguagem C sem uso de funções de processamento do OpenCV.

A biblioteca para aquisição da câmera fornecida pelo [Profº Marcelo Hashimoto](https://www.github.com/mhsenac) para este trabalho pode ser encontrada [neste repositório](https://github.com/senacbcc/Hashimoto-Camera-lib).

####Integrantes
---------------------
##### Alunos:

[![Ezequiel França](https://0.gravatar.com/avatar/3b4da2efb9fda1566a2907dd551fc907?d=https%3A%2F%2Fidenticons.github.com%2F3a716d3607e5bf63ee1c167fa81c8f5d.png&r=x&s=50)](https://github.com/ezefranca) | [![Gabriel Fontenelle](https://avatars2.githubusercontent.com/u/3775677?s=50)](https://github.com/OdnaropX)
--- | --- | --- | --- | --- | --- | ---
[Ezequiel França](github.com/ezefranca) | [Gabriel Fontenelle](https://github.com/OdnaropX)

##### Professor Orientador:

[![cv](http://gediscursivos.files.wordpress.com/2012/12/lattes.png?w=869)](http://lattes.cnpq.br/5909154335340519)  [Profº Marcelo Hashimoto](https://www.github.com/mhsenac)


### Requisitos de instalação
----------------------

Git (opcional recomendado), Allegro 5.x e OpenCV instalados no sistema.

[![Git](https://raw.githubusercontent.com/ezefranca/BCC-1s14-PI3-Master-Exploder/master/others/travis/git.png)](http://git-scm.com/) | [![OpenCV](https://raw.githubusercontent.com/ezefranca/BCC-1s14-PI3-Master-Exploder/master/others/travis/opencv-logo.png)](http://www.opencv.org/) | [![Allegro5](https://raw.githubusercontent.com/ezefranca/BCC-1s14-PI3-Master-Exploder/master/others/travis/allegro-logo.png)](http://alleg.sourceforge.net/)
--- | --- | --- | --- | --- | --- | ---
[Git](http://git-scm.com/) | [OpenCV](http://www.opencv.org/) | [Allegro5](http://alleg.sourceforge.net/)


#### Windows
-----------------------
![Windows](https://raw.githubusercontent.com/ezefranca/BCC-1s14-PI3-Master-Exploder/master/others/travis/windows.png)

##### Compile o Allegro e OpenCV para usar por prompt de comando seguindo o tutorial: [Compilando no Windows](https://github.com/ezefranca/BCC-1s14-PI3-Master-Exploder/wiki/Compila%C3%A7%C3%A3o-e-Instala%C3%A7%C3%A3o-Allegro-5-e-OpenCV-no-Windows)


#### Linux
-----------------------
![Linux](https://raw.githubusercontent.com/ezefranca/BCC-1s14-PI3-Master-Exploder/master/others/travis/linux.png)

###### Consulte o projeto: [> EnviromentSetup](https://github.com/senacbcc/OpenCV-Allegro5-InstallScript)
Agradecimentos a [Gabriel Garcia](https://github.com/GabrielGarcia1)

#### OSX
--------
![OSX](https://raw.githubusercontent.com/ezefranca/BCC-1s14-PI3-Master-Exploder/master/others/travis/osx.png)

Utilizando [Homebrew](https://github.com/Homebrew/homebrew)

##### [Instalando Homebrew](https://github.com/Homebrew/homebrew.wiki.git)

Com o brew instalado:

```
$ brew install opencv
$ brew install homebrew/versions/allegro5
```

Após a instalação do Allegro5 e do openCV faça uma cópia do código fonte através do git,

```bash
$ git clone git@github.com:ezefranca/BCC-1s14-PI3-Master-Exploder.git
```
ou, 

baixe o projeto todo compactado em zip [![Download Zip](https://raw.github.com/ezefranca/BCC-1s14-PI3-Master-Exploder/master/travis-install/zip-download.png)](https://github.com/ezefranca/BCC-1s14-PI3-Master-Exploder/archive/master.zip).


### Como compilar
---------------------------



#### Linux / MacOSX
----------------------------
![Linux](https://raw.githubusercontent.com/ezefranca/BCC-1s14-PI3-Master-Exploder/master/others/travis/linux.png)
![OSX](https://raw.githubusercontent.com/ezefranca/BCC-1s14-PI3-Master-Exploder/master/others/travis/osx.png)


Navegue até o diretório do projeto e digite:

```bash
$ make
```
para executar

```bash
$ cd bin
$ ./main
```

#### Windows com MinGW:
-----------------------------
![Windows](https://raw.githubusercontent.com/ezefranca/BCC-1s14-PI3-Master-Exploder/master/others/travis/windows.png)

Navegue até o diretório do projeto e digite:

```bash
$ mingw32-make
```

####Master Exploder
-----------------

O nome "Master Exploder" é uma referência a uma das músicas da banda [Tenacius D](http://en.wikipedia.org/wiki/Tenacious_D) no album (e filme) [The Pick of Destiny](http://en.wikipedia.org/wiki/The_Pick_of_Destiny)


####Licença e Créditos
----------------------

Este trabalho foi licenciado sob uma [Licença Creative Commons Atribuição-CompartilhaIgual 3.0 Brasil.](http://creativecommons.org/choose/results-one?license_code=by-sa&jurisdiction=br&version=2.5&lang=pt_BR)

This work is licensed under a [Creative Commons Attribution-ShareAlike 3.0 Unported License.](http://creativecommons.org/licenses/by-sa/3.0/)

![My image](http://i.creativecommons.org/l/by-sa/3.0/88x31.png)


