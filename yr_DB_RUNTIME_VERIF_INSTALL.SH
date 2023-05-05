#!/bin/sh
# @author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU, YEROTH R&D

# SHOWS THIS Makefile FILE COMMAND STRING IN THE
# CONSOLE AS THEY ARE EXECUTED.
set -x


sudo gdebi -n yr-db-runtime-verif.deb

sudo systemctl daemon-reload


