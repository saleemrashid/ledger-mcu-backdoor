# Ledger MCU Backdoor

Proof-of-concept exploit for the Ledger Nano S that hides the non-genuine user
interface confirmation. Intentionally unreliable to avoid weaponization.

It should be trivial to adapt to the Ledger Blue.

[More information](https://saleemrashid.com/2018/03/20/breaking-ledger-security-model/)

## Installation

1. [Set up the ARM toolchain](https://ledger.readthedocs.io/en/latest/userspace/getting_started.html)

2. Turn on the Ledger Nano S with the left button held until "Bootloader" is displayed

3. Build and install the modified firmware

```bash
make vendor
make load
```

4. To restore the official firmware

```bash
make delete
```
