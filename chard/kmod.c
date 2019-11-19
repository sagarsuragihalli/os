#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/sched.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/slab.h>
#include<asm/uaccess.h>

MODULE_LICENSE ("Dual BSD/GPL");

//constants

#define FIRST_MINOR 10
#define NR_DEVS 1  //Number of device numbers

//function declarations for syscall definitions

int myOpen(struct inode *inode,struct file *filep);
int myRelease(struct inode *inode,struct file *filep);

//initialization routines

static int myInit (void);
void myExit (void);

struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = myOpen,
	.release = myRelease
};

//global variables

char *devname;  //contains device name
int majNo;
dev_t mydev;	//encodes the major and minor number
struct cdev *my_cdev;	//holds characters device driver descriptor

//to accept input from the command line

module_param(devname,charp,0000);

//class and device structures 

struct class *mychar_class;
struct device *mychar_device;

/*
*myOpen:open function to the pseudo driver
*/

int myOpen (struct inode *inode, struct file *filep)
{
	printk(KERN_INFO"OPen successful\n");
	return 0;
}

/*
*myRelease: close funtion to the pseudo driver
*/

int myRelease (struct inode *inode,struct file *filep)
{
	printk(KERN_INFO"File released\n");
	return 0;
}

/*
* myInit :init function of kernel module
*/

int __init myInit (void)
{
	int ret = -ENODEV;
	int status;
	printk(KERN_INFO "Initializing character Device\n");

	//allocating device numbers
	status = alloc_chrdev_region (&mydev, FIRST_MINOR, NR_DEVS, devname);
	if(status < 0)
	{
		printk(KERN_NOTICE "Device numbers allocation failed : %d\n",status);
		goto err;
	}
	printk(KERN_INFO "Major number allocated = %d \n",status);
	
	my_cdev = cdev_alloc();//allocate memory for my_cdev
	if(my_cdev == NULL)
	{
		printk(KERN_ERR "cdev_alloc failed \n");
		goto err_cdev_alloc;
	}
	
	cdev_init(my_cdev, &fops);	//initialize my_cdev
	my_cdev->owner = THIS_MODULE;
	
	status = cdev_add (my_cdev, mydev, NR_DEVS);	//add my cdev to the list
	if(status)
	{
		printk(KERN_ERR "cdrv_add failed \n");
		goto err_cdev_add;
	}
	
	//create a class and an entry in sysfs
	
	mychar_class = class_create (THIS_MODULE, devname);
	if(IS_ERR(mychar_class))
	{
		printk(KERN_ERR "class_create() failed \n");
		goto err_class_create;
	}

	//create mychar in sysfs and a device entry will be made in /dev directory

	mychar_device = device_create (mychar_class, NULL, mydev, NULL, devname);
	if(IS_ERR(mychar_device))
	{
		printk (KERN_ERR "device_create() failed \n");
		goto err_device_create;
	}
	
	return 0;

err_device_create:
	class_destroy (mychar_class);

err_class_create:
	cdev_del (my_cdev);

err_cdev_add:
	kfree (my_cdev);

err_cdev_alloc:
	unregister_chrdev_region (mydev, NR_DEVS);

err:
	return ret;
}



module_init (myInit);



