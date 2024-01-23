# lacheze_lab1

# Présentation
Le cours d'ESN11 set à mettre en oeuvre les connaissance apprise lors du cours de conception conjointe. Le but de ces TP est de se familiariser avec les systèmes basés sur un nios-II. Nous utilisons une carte électronique DE-10 lite qui contient un FPGA.
L'objectif de ce lab est d'implementer un chenillard à vitesse variable sur la carte.


# Architecture

Voici l'achitecture de notre système:
![image](https://github.com/ESN2024/lacheze_lab1/assets/147801348/8e8e11d1-25ce-49c9-bd65-d2d8bec0035f)

On remarque sur l'image les pios utilisés, un pio pour les sorties ici les leds et un pio pour les entrées ici le bouton poussoir et les switchs. J'ai mis les switch et le bouton poussoir dans le même piobp car la consigne ne demande d'utiliser que 4 switchs sur les 10. Une interruption a été mise entre le piobp et le nios-II car cela permet de lancer le chenillard sur le bouton poussoir et de changer la vitesse du chenillard via les 4 switchs.

