.PHONY: all
all:
	arm-linux-g++ -o main eLine_main.cpp eLine_fb.cpp
	mv main /home/wpf/work/eiwPhone/eLinux/rootfs/eiwPhone/
	
.PHONY: clean
clean:
	rm -f /home/wpf/work/eiwPhone/eLinux/rootfs/eiwPhone/main
