#!/bin/bash

#############################################################################
#Script Name	: install.sh                                                                                             
#Description	: verifies and installs dependencies to properly run the code                                                                                                                                                                         
#Author       	: João Victor M. Barboza                                                
#Email         	: victorbarboza7657@gmail.com                                           
#############################################################################

echo "Welcome! Would you like to automatically install dependencies not installed?:[type yes/no]"
read ans

name=g++

dpkg -s $name &> /dev/null

if [ $? -ne 0 ];
then
	echo "g++ not installed"
	if [ $ans = "yes" ];
	then
		yes | sudo apt-get install g++
	else
		echo "it can be installed with: sudo apt-get install g++"
	fi
else
	echo "g++ already installed [x]"
fi

name=python3  

dpkg -s $name &> /dev/null

if [ $? -ne 0 ];
then
        echo "python not installed"
	if [ $ans = "yes" ];
	then
		yes | sudo add-apt-repository ppa:ubuntu-toolchain-r/ppa
		yes | sudo apt install python3.7
	else
		echo "it can be installed with: sudo apt install python3.7"
	fi
else
        echo "python already installed [x]"
fi

name=pip  

dpkg -s $name &> /dev/null

if [ $? -ne 0 ];
then
        echo "pip not installed"
	if [ $ans = "yes" ];
	then
		yes | sudo apt install python3-pip
		
		echo "installing python packages"
		pip3 install -r requirements.txt
	else
		echo "it can be installed with: sudo apt install python3-pip"
	fi
else
        echo "pip already installed [x]"
	pip3 install -r requirements.txt

fi