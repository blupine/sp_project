#include <linux/gpio.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/delay.h>

#define GPIO_R 22//GPIO.24
#define GPIO_G 27//GPIO.23
#define GPIO_B 17//GPIO.22

#define DEV_NAME "3led_dev"
#define DEV_NUM 262

MODULE_LICENSE("GPL");

int led_open(struct inode* pinode, struct file* pfile){
	printk(KERN_ALERT "OPEN led__dev\n");
	gpio_request_one(GPIO_R,1, "GPIO_R");
	gpio_request_one(GPIO_G,1, "GPIO_G");
	gpio_request_one(GPIO_B,1, "GPIO_B");

	if(gpio_direction_output(GPIO_R, 1) != 0) printk("err GPIO_R\n");
	if(gpio_direction_output(GPIO_G, 1) != 0) printk("err GPIO_G\n");
	if(gpio_direction_output(GPIO_B, 1) != 0) printk("err GPIO_B\n");

	return 0;
}

int led_close(struct inode* pinode, struct file* pfile){
	printk(KERN_ALERT "RELEASE led_dev\n");
	gpio_free(GPIO_R);
	gpio_free(GPIO_G);
	gpio_free(GPIO_B);

	return 0;
}

ssize_t led_write(struct file* pfile, const char __user* buffer, size_t length, loff_t* offset){
	char msg[4]="";

	if(copy_from_user(msg, buffer, length) < 0){
		printk("led_dev write error\n");
		return -1;
	}
	msg[0] == '1' ?	gpio_set_value(GPIO_R, 0) : gpio_set_value(GPIO_R, 1);
	msg[1] == '1' ?	gpio_set_value(GPIO_G, 0) : gpio_set_value(GPIO_G, 1);
	msg[2] == '1' ?	gpio_set_value(GPIO_B, 0) : gpio_set_value(GPIO_B, 1);
	printk("msg : %c %c %c\n",msg[0],msg[1],msg[2]);
	return length;
}

struct file_operations fop = {
	.owner = THIS_MODULE,
	.open = led_open,
	.write = led_write,
	.release = led_close,
};

int __init touch_init(void){
	printk(KERN_ALERT "INIT led_dev\nsudo mknod -m 666 /dev/3led_dev c 262 0\n");
	register_chrdev(DEV_NUM, DEV_NAME, &fop);
	return 0;
}

void __exit touch_exit(void){
	printk(KERN_ALERT "EXIT led_dev\n");
	unregister_chrdev(DEV_NUM, DEV_NAME);
}

module_init(touch_init);
module_exit(touch_exit);
