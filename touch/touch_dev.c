#include <linux/gpio.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define GPIO1 40//GPIO.29
#define GPIO2 38//GPIO.28
#define GPIO3 36//GPIO.27
#define GPIO4 32//GPIO.26

#define DEV_NAME "touch_dev"
#define DEV_NUM 250

MODULE_LICENSE("GPL");

int touch_open(struct inode* pinode, struct file* pfile){
	printk(KERN_ALERT "OPEN touch_dev\n");
	gpio_request(GPIO1, "GPIO1");
	gpio_request(GPIO2, "GPIO2");
	gpio_request(GPIO3, "GPIO3");
	gpio_request(GPIO4, "GPIO4");

	gpio_direction_input(GPIO1);
	gpio_direction_input(GPIO2);
	gpio_direction_input(GPIO3);
	gpio_direction_input(GPIO4);

	return 0;
}

int touch_close(struct inode* pinode, struct file* pfile){
	printk(KERN_ALERT "RELEASE touch_dev\n");
	gpio_free(GPIO1);
	gpio_free(GPIO2);
	gpio_free(GPIO3);
	gpio_free(GPIO4);
	return 0;
}

ssize_t touch_read(struct file* pfile, char __user* buffer, size_t length, loff_t* offset){
	printk("Read touch_dev\n");
	char buf[4];
	buf[0] = (char)gpio_get_value(GPIO1);
	buf[1] = (char)gpio_get_value(GPIO2);
	buf[2] = (char)gpio_get_value(GPIO3);
	buf[3] = (char)gpio_get_value(GPIO4);

	copy_to_user(buffer,buf,length);

	return 0;
}

struct file_operations fop = {
	.owner = THIS_MODULE,
	.open = touch_open,
	.release = touch_close,
};

int __init touch_init(void){
	printk(KERN_ALERT "INIT touch_dev\n");
	register_chrdev(DEV_NUM, DEV_NAME, &fop);
	return 0;
}

void __exit touch_exit(void){
	printk(KERN_ALERT "EXIT touch_dev\n");
	unregister_chrdev(DEV_NUM, DEV_NAME);
}

module_init(touch_init);
module_exit(touch_exit);
