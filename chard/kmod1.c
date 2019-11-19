#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/sched.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/slab.h>
#include<asm/uaccess.h>

#define FIRST_MINOR 10
#define NR_DEVS 1 

extern char *devname;  //contains device name
extern int majNo;
extern dev_t mydev;	//encodes the major and minor number
extern struct cdev *my_cdev;	//holds characters device driver descriptor

extern struct class *mychar_class;
extern struct device *mychar_device;

/*
* myExit: cleanup function of the kernel
*/
void myExit (void)
{
	printk (KERN_INFO "Exiting the character driver \n");
	device_destroy (mychar_class, mydev);
	class_destroy (mychar_class);
	cdev_del (my_cdev);
	unregister_chrdev_region (mydev, NR_DEVS);
	
	return;
}

module_exit (myExit);

