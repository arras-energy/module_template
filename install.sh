echo 'git clone https://github.com/${REPO} ${GLD_SRC}/module/${NAME} -b ${BRANCH:-master} --depth 1' | gridlabd shell
echo 'cd ${GLD_SRC}/module/${NAME}/source;make install' | gridlabd shell
