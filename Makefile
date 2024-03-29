all:
	g++ -I source/include -L source/lib -o main main.cpp initialisation.cpp random_generator.cpp affichage.cpp update.cpp force.cpp norme.cpp -lmingw32 -lSDL2main -lSDL2


### important : noter tous les fichiers sources après main.cpp initialisation.cpp random_generator.cpp 
### sinon le compilateur ne comprends pas et lit les fichiers indépendament 