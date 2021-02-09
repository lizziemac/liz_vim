SED='sed -i'
DARWIN_SCRIPTS_ARRAY=( \
    check_xdot_version \
    exec_deploy_remote \
    exec_run_gw_tests \
    exec_deploy_xdot \
    exec_manual_deploy_remote \
    exec_program_zwave \
    finalize_gw \
    remote_deployment_version \
    xdot_deployment_version \
    select_candidate \
)


for i in "${DARWIN_SCRIPTS_ARRAY[@]}";
    do echo "$i";
done

$SED '' 's@replaceMe@cd\ '"TEST"'@g' select_candidate.sh