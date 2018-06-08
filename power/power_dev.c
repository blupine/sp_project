#include <linux/gpio.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define GPIO_OUT 12//temp GPIO
#define DEV_NAME "power_dev"
#define DEV_NUM 262

MODULE_LICENSE("GPL");

int power_open(struct inode* pinode, struct file* pfile){
	printk(KERN_ALERT "OPEN power_dev\n");
	gpio_request(GPIO_OUT, "GPIO_POWER");
	if(gpio_direction_output(GPIO_OUT,0) != 0)	printk("error power\n");

	return 0;
}

int power_close(struct inode* pinode, struct file* pfile){
	printk(KERN_ALERT "RELEASE power_dev\n");
	gpio_free(GPIO_OUT);

	return 0;
}

ssize_t power_write(struct file* pfile, const char __user* buffer, size_t length, loff_t* offset){
	char* buf;
	buf = kmalloc(2, GFP_KERNEL);

	copy_from_user(buf, buffer, 1);

	if(buf[0] == '1'){
		printk("1");
		gpio_set_value(GPIO_OUT, 1);
	}
	else if(buf[0] == '2'){
		printk("2");
		gpio_set_value(GPIO_OUT, 0);
	}

	printk("Write power_dev %c\n",buf[0]);

	return length;
}

struct file_operations fop = {
	.owner = THIS_MODULE,
	.open = power_open,
	.write = power_write,
	.release = power_close,
};

int __init power_init(void){
	printk(KERN_ALERT "INIT power_dev\n");
	register_chrdev(DEV_NUM, DEV_NAME, &fop);
	return 0;
}

void __exit power_exit(void){
	printk(KERN_ALERT "EXIT power_dev\n");
	unregister_chrdev(DEV_NUM, DEV_NAME);
}

module_init(power_init);
module_exit(power_exit);
