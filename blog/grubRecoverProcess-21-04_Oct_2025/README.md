---
title: Pasi de recuperare a pt grub
date: 2025-10-04T18:13:10+03:00
subject: blog
description: 
tags: ["linux","grub"]
uniYearAndSemester: 21
---

### Comenzile de mai jos sunt doar reprezentative, si folosite doar pentru a ilustra pasii care trebuie urmati
De asemenea acestea comenzile sunt scrise pentru sisteme care folosesc btrfs, insa pot fi usor adaptate pt orice alt sistem


```bash

lsblk -f

mount /dev/nvme0n1p2 /mnt

umount /mnt

btrfs subvolume list /mnt

mount -o subvol=@ /dev/nvme0n1p2 /mnt

mkdir /mnt/boot

mount /dev/nvme0n1p1 /mnt/boot

arch-chroot /mnt

grub-install --target=x86_64-efi --efi-directory=/boot/efi --bootloader-id=GRUB

# In cazul in care doresti sa adaugi windows la boot loader
# GRUB_DISABLE_OS_PROBER=true
nvim /etc/default/grub

sudo grub-mkconfig -o /boot/grub/grub.cfg



```

