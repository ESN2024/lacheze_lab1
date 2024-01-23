# lacheze_lab1

# Présentation
Le cours d'ESN11 set à mettre en oeuvre les connaissance apprise lors du cours de conception conjointe. Le but de ces TP est de se familiariser avec les systèmes basés sur un nios-II. Nous utilisons une carte électronique DE-10 lite qui contient un FPGA.
L'objectif de ce lab est d'implementer un chenillard à vitesse variable sur la carte.


# Architecture

Voici l'achitecture de notre système:

![image](https://github.com/ESN2024/lacheze_lab1/assets/147801348/afd02c1e-e9eb-4ca1-9ec6-452f668ba6af)

Le schéma possède des éléments qui seront utilisé aussi lors de la création de lab2 et lab3 à savoir le nios-II, le AVMM, la clock de 50Mhz et le jtag qui nous sert au debug du système.
On remarque sur l'image les pios utilisés, un pio pour les sorties ici les leds et un pio pour les entrées ici le bouton poussoir et les switchs. J'ai mis les switch et le bouton poussoir dans le même piobp car la consigne ne demande d'utiliser que 4 switchs sur les 10. Une interruption a été mise entre le piobp et le nios-II car cela permet de lancer le chenillard sur le bouton poussoir et de changer la vitesse du chenillard via les 4 switchs.

# Design QSYS

Voici le design que j'ai réalisé sur platform designer:
![image](https://github.com/ESN2024/lacheze_lab1/assets/147801348/a2ecfdfd-5ef2-480a-93f4-3afbbc91b506)

On retrouve bien les différents éléments qui ont été décris dans l'architecture du système ainsi que l'interruption qui permettra de lancer le chenillard et de modifier sa vitesse.

 # Mise en oeuvre du lab

 Après avoir réalisé le design qsys sur platform designer, j'ai crée un fichier vhd qui contient l'instanciation du design, puis on relie les entrées/sorties du fichier vhd aux broches de la carte via Pin Planner.
 Après Compilation du design sur Quartus, j'ai généré le bsp du système afin de pourvoir utiliser les drivers et fonction lié aux éléments du design qsys (piobp , clock, interruptions).

 ## Travail réalisé
 Le lab était décomposé en 4 parties:
 -allumer un led
 -réaliser un chenillard qui se lance automatiquement
 -réaliser un chenillard qui se lance lorsque un bouton poussoir est pressé
 -réaliser un chenillard qui se lance lorsque un bouton poussoir est pressé et dont la vitesse varie en fonction des switchs

 Pour chaque partie, j'ai réalisé un fichier .c différent et j'ai dut générer un makefile à chaque fois.

 ### Allumer une led
 Le fichier.c correspondant est le main.c. Le programme consiste en une simple fonction _IOWR_ALTERA_AVALON_PIO_DATA(base, data)_ qui va commander l'ensemble des led. La base correspond à l'adresse des led dans le système. Dans data, on met 0x01 afin d'allumer seulement la derniere led.
 
![image](https://github.com/ESN2024/lacheze_lab1/assets/147801348/0d31c0cd-d28b-4293-8141-871efb2c1e5c)

### Réaliser un chenillard qui se lance automatiquement
Le fonctionnement du chenillard utilise la même fonction que précédemment. Sauf que ici, pour changer la position de la led, on effectue un décalage à gauche dans la variable adresse(data dans IOWR_ALTERA_AVALON_PIO_DATA). Lorsque la variable adresse a un 1 dans son bit de poids fort, on remet son adresse a sa valeur initiale. Un délai qui donne un affichage périodique permet de réaliser ce chenillard.

![image](https://github.com/ESN2024/lacheze_lab1/assets/147801348/2de3ffdf-dad2-4fa4-86aa-e026e7b3112b)

### Réaliser un chenillard qui se lance lorsque un bouton poussoir est pressé
Le fonctionnement du chenillard reprend le même modèle que la fonction précédente. On utilise une interruption sur le bouton poussoir afin de lancer le chenillard, la partie commande des led est passé dans l'interruption et le main ne contient que l'initialisation de l'interruption et les fonctions necessaires à l'interruption. 

Le code se trouve dans chenillard_irq.c

### Réaliser un chenillard qui se lance lorsque un bouton poussoir est pressé et dont la vitesse varie en fonction des switchs

Pour réaliser le chenillard avec les switch, on réutilise l'interruption d'avant mais on change les valeurs du masque de l'interruption afin de récupérer les switchs. Une variable timer a été créee et change dans l'interruption lorsque qu'un switch change de position, la variable de delai est maintenant proportionnelle à aux switchs mis à 1. Pour définir si l'interruption vient du bp pour lancer le chenillard ou si elle vient des switchs, on fait un masque sur la valeurs des pio (bp + switchs) et on teste si les valeurs sont à 1. 

Le code se trouve dans chenillard_irq_sw.c

# Réalisation
