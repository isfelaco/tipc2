# CLion remote toolchain for tipc developemnt on HPC cluster

 
> CLion 2022.3.2 | Build #CL-223.8617.54, built on January 25, 2023
> 
> macOS Ventura 13.5 (22G74)


## Setup .bash_profile in UVa CS Portal
1. Log-in to your portal shell using your terminal.
2. Execute the following command to load modules and set environment parameters at login
```shell
echo "module load clang-llvm-14.0.6 && export TIPCLANG=`which clang`" >>~/.bash_profile
```

## Setup SSH profile

1. Open CLion, goto `Settings | Tools | SSH Configurations` and click `+` to add new configuration
2. Fill in your portal credentials and make sure rest of your configuration looks like the following:
![ssh-add.png](clion-remote-dev-img%2Fssh-add.png)

3. Click `Test Connection` and you should see `Successfully connected!` as following -

![ssh-Okay-connect.png](clion-remote-dev-img%2Fssh-Okay-connect.png)


## Setup remote toolchain

1. Go to `Settings | Build, Execution, Deployment | Toolchains` and click `+` icon and select Remote Host from the drop-down menu to create a new toolchain.

![add-remote.png](clion-remote-dev-img%2Fadd-remote.png)

2. Existing SSH configurations are available from the drop-down list. To add a new configuration click the gear icon next to the Credentials field. In the dialog that opens, choose your previously created SSH configuration.

![remote-portal-config.png](clion-remote-dev-img%2Fremote-portal-config.png)


## Create a corresponding CMake profile

1. Go to `Settings | Build, Execution, Deployment | CMake`
2. Click `+` to create a new CMake profile, then select your Remote Toolchain from the dropdown after `Toolchain` section.

![cmake-toolchain-select.png](clion-remote-dev-img%2Fcmake-toolchain-select.png)

3. Make sure that other parameters match the following -
![remote-cmake-configuration.png](clion-remote-dev-img%2Fremote-cmake-configuration.png)

---

#### References
[1] [https://www.jetbrains.com/help/clion/remote-projects-support.html](https://www.jetbrains.com/help/clion/remote-projects-support.html)

[2] [https://www.jetbrains.com/help/clion/cmake-profile.html](https://www.jetbrains.com/help/clion/cmake-profile.html)