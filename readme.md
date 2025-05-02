# AI-Ads Generator

Un utilitaire en ligne de commande pour générer automatiquement des publicités vidéo simples avec narration audio à partir d'un texte.

## Description

Ce projet fournit un outil qui génère des publicités vidéo basiques avec du texte et une narration audio en utilisant l'API Google Cloud Text-to-Speech pour la synthèse vocale et FFmpeg pour la génération de vidéo.

## Fonctionnalités

- Conversion de texte en parole via l'API Google Cloud Text-to-Speech
- Génération de vidéos avec texte superposé
- Combinaison de la vidéo et de l'audio pour créer une publicité complète

## Prérequis

- GCC ou autre compilateur C
- libcurl (pour les requêtes HTTP)
- FFmpeg (pour la manipulation vidéo)
- Une clé API Google Cloud avec Text-to-Speech activé

## Installation

1. Clonez ce dépôt :
   ```
   git clone https://github.com/votre-nom/ai-ads-generator.git
   cd ai-ads-generator
   ```

2. Compilez le projet :
   ```
   make
   ```

## Configuration

Avant d'utiliser l'application, vous devez remplacer `"YOUR_GOOGLE_API_KEY"` dans le fichier `main.c` par votre propre clé API Google Cloud.

Vous devrez également spécifier le chemin correct vers la police de caractères dans le fichier `video.c` en modifiant la ligne suivante :
```c
"ffmpeg -f lavfi -i color=c=black:s=1280x720:d=10 -vf \"drawtext=fontfile=/path/to/font.ttf..."
```

## Utilisation

1. Modifiez le nom du produit dans `main.c` :
   ```c
   const char *product_name = "Votre Produit";
   ```

2. Exécutez le programme :
   ```
   ./generate_ad
   ```

3. Le résultat sera enregistré en tant que `final_ad.mp4` dans le répertoire courant.

## Structure du Projet

- `main.c` - Point d'entrée du programme
- `tts.h/tts.c` - Module pour les fonctionnalités de synthèse vocale
- `video.h/video.c` - Module pour la génération de vidéo
- `makefile` - Configuration de compilation

## Personnalisation

Vous pouvez personnaliser votre publicité en modifiant les éléments suivants :
- Texte de la publicité dans `video.c`
- Voix TTS (actuellement configurée sur "en-US-Wavenet-D")
- Taille et couleur de la vidéo
- Police, taille et couleur du texte

## Limitations

- La publicité générée est une vidéo simple avec du texte statique
- Nécessite une connexion Internet pour utiliser l'API Google Text-to-Speech
- Actuellement, seul le format MP3 est pris en charge pour l'audio

## Licence

[Spécifiez votre licence ici]

## Contributeurs

[Ajoutez vos informations de contact ici]