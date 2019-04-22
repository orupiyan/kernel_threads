echo "Opening screen by typing: gnome-terminal -x sh -c \"screen /dev/ttyUSB3 115200s; bash\""
gnome-terminal -x sh -c "screen /dev/ttyUSB3 115200s; bash"
echo "IMAGE_DIR=\'/home/parallels/EmbeddedLinux/Assignments/Assignment5/2017-chipBootImages\'"
IMAGE_DIR='/home/parallels/EmbeddedLinux/Assignments/Assignment5/2017-chipBootImages'
echo "FEL_DIR=\'/home/parallels/EmbeddedLinux/WorkingFolder/sunxi-tools\'"
FEL_DIR='/home/parallels/EmbeddedLinux/WorkingFolder/sunxi-tools'

echo "fel version"
${FEL_DIR}/fel version
echo "fel spl sunxi-spl.bin"
${FEL_DIR}/fel spl ${IMAGE_DIR}/sunxi-spl.bin
echo "fel -p write 0x4a000000 u-boot-dtb.bin"
${FEL_DIR}/fel -p write 0x4a000000 ${IMAGE_DIR}/u-boot-dtb.bin
echo "fel -p write 0x42000000 zImage"
${FEL_DIR}/fel -p write 0x42000000 ${IMAGE_DIR}/zImage
echo "fel -p write 0x43000000 sun5i-r8-chip.dtb"
${FEL_DIR}/fel -p write 0x43000000 ${IMAGE_DIR}/sun5i-r8-chip.dtb
echo "fel -p write 0x43100000 uboot-initrd.scr"
${FEL_DIR}/fel -p write 0x43100000 ${IMAGE_DIR}/uboot-initrd.scr
echo "fel -p write 0x43300000 initramfs-NEW.cpio.gz.uImage"
${FEL_DIR}/fel -p write 0x43300000 ${IMAGE_DIR}/initramfs-NEW.cpio.gz.uImage
echo "fel exe 0x4a000000"
${FEL_DIR}/fel exe 0x4a000000



