#!/bin/bash
# @author: PROF. DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU

USAGE="Usage: $(basename $0) <-d USER_POROJECT_DIR>"

if [ $# -lt 2 ]; then
  echo "$USAGE"
  exit 1
fi

userprojectdirectoryFlag=

USER_PROJECT_REL_PATH_DIRECTORY_VAL=

while getopts 'd:' OPTION
do
  case $OPTION in
    d)	projectdirectoryFlag=1
      	USER_PROJECT_REL_PATH_DIRECTORY_VAL="$OPTARG"
        #echo new string: ${nval} 
	;;
    ?)	printf "$USAGE" >&2
        exit 2
	;;
  esac
done
shift $(($OPTIND - 1))


YR_DB_RUNTIME_VERIF_DEVEL_HOME="${PWD}"


USER_PROJECT_FULL_PATH_DIRECTORY_VAL="${YR_DB_RUNTIME_VERIF_DEVEL_HOME}/${USER_PROJECT_REL_PATH_DIRECTORY_VAL}"


cd "${USER_PROJECT_FULL_PATH_DIRECTORY_VAL}"

cd bin

. yr-sd-mealy-machine-runtime-monitor-generator.sh

cd "${YR_DB_RUNTIME_VERIF_DEVEL_HOME}"

./GENERATE_INCLUSION_CODE_runtime_monitor.sh

./yr_compile_j4.sh


