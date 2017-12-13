#!/bin/bash
#Daniel Vila
git add *
echo "Introduzca un mensaje para el commit"
read mensaje
git commit -m "$mensaje"
git push -u https://github.com/Danvilgom/Interfaces.git master
