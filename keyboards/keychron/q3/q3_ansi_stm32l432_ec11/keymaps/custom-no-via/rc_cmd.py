#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

import sys
import hid ## https://pypi.org/project/hid/
import time
import struct


COMMANDS = {
    "SET_MIC_ON": 50,
    "SET_MIC_OFF": 51,
    "SET_MUTE_ON": 52,
    "SET_MUTE_OFF": 53,
}


def pad_message(payload):
    max_len = 64
    ret = payload + (b'\x00' * (max_len - len(payload)))
    assert len(ret) == 64
    return ret


def main(args):
    target_dev = None

    for _d in hid.enumerate():
        if _d["usage"] == 0x61 and _d["usage_page"] == 0xFF60:
            target_dev = _d
            break

    assert target_dev is not None, "couldn't find HID device"

    with hid.Device(target_dev["vendor_id"], target_dev["product_id"]) as conn:
        # print(f'Device manufacturer: {conn.manufacturer}')
        # print(f'Product: {conn.product}')
        # print(f'Serial Number: {conn.serial}')

        # enable non-blocking mode
        # conn.set_nonblocking(1)

        for cmd in [ pad_message(struct.pack("<xb", COMMANDS[a])) for a in args ]:
            assert conn.write(cmd) == 64, "short write"

            time.sleep(0.05)


if __name__ == "__main__":
    main(sys.argv[1:])
