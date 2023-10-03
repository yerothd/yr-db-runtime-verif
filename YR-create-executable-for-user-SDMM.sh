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
	;;
    ?)	printf "$USAGE" >&2
        exit 2
	;;
  esac
done
shift $(($OPTIND - 1))


set -x


YR_DB_RUNTIME_VERIF_DEVEL_HOME="${PWD}"


USER_PROJECT_FULL_PATH_DIRECTORY_VAL="${YR_DB_RUNTIME_VERIF_DEVEL_HOME}/${USER_PROJECT_REL_PATH_DIRECTORY_VAL}"


cd ${USER_PROJECT_REL_PATH_DIRECTORY_VAL}


. bin/configuration-properties.sh


cd ..


for f in $(dir ${COMPILER_GENERATED_OUTPUT_FOLDER_FULL_PATH});
do
    YR_INCLUDE_PATH=$(basename $f)

    rm -f src/${YR_INCLUDE_PATH}
done


rm -rf ${COMPILER_GENERATED_OUTPUT_FOLDER_FULL_PATH}


git checkout yr-db-runtime-verif.pro
git checkout Makefile
git checkout src/yr-db-runtime-verif.cpp



cd "${USER_PROJECT_FULL_PATH_DIRECTORY_VAL}"

cd bin

. yr-sd-mealy-machine-runtime-monitor-generator.sh

cd "${YR_DB_RUNTIME_VERIF_DEVEL_HOME}"

./GENERATE_INCLUSION_CODE_runtime_monitor.sh

set +x

echo "*** NOW MODIFY the generated source files; Then build ***"
echo "*** Your project ("'./yr_db_runtime_verif_BUILD_DEBIAN_PACKAGE.sh' ***") !"


