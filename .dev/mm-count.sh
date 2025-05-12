#!/bin/bash

# Vérifie qu’un fichier est fourni
if [ $# -ne 1 ]; then
	echo "Usage: $0 <fichier_log>"
	exit 1
fi

logfile="$1"

# Vérifie que le fichier existe
if [ ! -f "$logfile" ]; then
	echo "Fichier introuvable: $logfile"
	exit 1
fi

# Parse les lignes et extrait les buckets
grep -oE 'bucket [0-9]+' "$logfile" | awk '{print $2}' | sort -n | uniq -c | sort -nr
