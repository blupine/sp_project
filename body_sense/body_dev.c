#include <linux/gpio.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define GPIO_OUT 12//temp GPIO
#define DEV_NAME "body_dev"
#define DEV_NUM 261

MODULE_LICENSE("GPL");

int body_open(struct inode* pinode, struct file* pfile){
	printk(KERN_ALERT "OPEN body_dev\n");
	gpio_request(GPIO_OUT, "GPIO_BODY");
	gpio_direction_input(GPIO_OUT);

	return 0;
}

int body_close(struct inode* pinode, struct file* pfile){
	printk(KERN_ALERT "RELEASE body_dev\n");
	gpio_free(GPIO_OUT);

	return 0;
}

ssize_t body_read(struct file* pfile, char __user* buffer, size_t length, loff_t* offset){
//	printk("Read body_dev\n");

	if(gpio_get_value(GPIO_OUT) == 1)	copy_to_user(buffer,"1",1);
	else	copy_to_user(buffer,"0",1);

	return 0;
}

struct file_operations fop = {
	.owner = THIS_MODULE,
	.open = body_open,
	.read = body_read,
	.release = body_close,
};

int __init body_init(void){
	printk(KERN_ALERT "INIT body_dev\nmajor 261\n");
	register_chrdev(DEV_NUM, DEV_NAME, &fop);
	return 0;
}

void __exit body_exit(void){
	printk(KERN_ALERT "EXIT body_dev\n");
	unregister_chrdev(DEV_NUM, DEV_NAME);
}

module_init(body_init);
module_exit(body_exit);
