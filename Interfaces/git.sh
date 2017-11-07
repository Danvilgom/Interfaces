#echo "# Interfaces1718" >> README.md
#git init
#echo "Escribe la carpeta que quieres añadir:"
#ls
#read carpeta
#git add $carpeta
git add *

echo "Introduzca el mensaje para el commit:"
read mensaje
git commit -m "$mensaje"
#git remote add origin https://github.com/Danvilgom/Interfaces1718.git
git push -u origin master
