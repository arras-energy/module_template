echo 'git clone -sL https://github.com/${REPO} ${GLD_SRC}/module/${NAME} -b ${BRANCH:-main} --depth 1' | gridlabd shell
echo 'cd ${GLD_SRC}/module/${NAME}/source;make install' | gridlabd shell
