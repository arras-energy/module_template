mkdir -p /usr/local/opt/gridlabd/current/src/module
git clone https://arras.energy/module_template template
cd template/source
echo "make install" | gridlabd shell
