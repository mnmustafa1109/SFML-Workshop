sudo su
apt-get install libsfml-dev
cd Development/Librairies/Linux/SFML/
cd include
cp -r SFML /usr/include/
cd ..
cp lib/* /usr/lib/