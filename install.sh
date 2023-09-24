export GRIDLABD=$(gridlabd --version=install)
mkdir -p ${GRIDLABD}/src/module
git clone https://github.com/${REPO} ${GRIDLABD}/src/module/${NAME} -b ${BRANCH:-master} --depth 1
cd ${GRIDLABD}/src/module/${NAME}/source
echo "make install" | gridlabd shell
