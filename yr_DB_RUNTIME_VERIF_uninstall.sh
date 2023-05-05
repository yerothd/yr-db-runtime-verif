#!/bin/sh
# @author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU, YEROTH R&D

# SHOWS THIS Makefile FILE COMMAND STRING IN THE
# CONSOLE AS THEY ARE EXECUTED.
set -x


sudo systemctl stop yr-db-runtime-verif

sudo apt -y --purge remove yr-db-runtime-verif

