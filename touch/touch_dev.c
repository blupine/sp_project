#include <linux/gpio.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/delay.h>

#define GPIO1 20//GPIO.28
#define GPIO2 16//GPIO.27
#define GPIO3 24//GPIO.5
#define GPIO4 23//GPIO.4

#define DEV_NAME "touch_dev"
#define DEV_NUM 260

MODULE_LICENSE("GPL");

int touch_open(struct inode* pinode, struct file* pfile){
	printk(KERN_ALERT "OPEN touch_dev\n");
	gpio_request(GPIO1, "GPIO1");
	gpio_request(GPIO2, "GPIO2");
	gpio_request(GPIO3, "GPIO3");
	gpio_request(GPIO4, "GPIO4");

	if(gpio_direction_input(GPIO1) != 0) printk("err GPIO1\n");
	if(gpio_direction_input(GPIO2) != 0) printk("err GPIO1\n");
	if(gpio_direction_input(GPIO3) != 0) printk("err GPIO1\n");
	if(gpio_direction_input(GPIO4) != 0) printk("err GPIO1\n");

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
	char* buf;
	buf = kmalloc(4, GFP_KERNEL);
	gpio_get_value(GPIO1) == 1 ?	buf[0] = '1' : buf[0] == '0';
	gpio_get_value(GPIO2) == 1 ?	buf[1] = '1' : buf[1] == '0';
	gpio_get_value(GPIO3) == 1 ?	buf[2] = '1' : buf[2] == '0';
	gpio_get_value(GPIO4) == 1 ?	buf[3] = '1' : buf[3] == '0';
	printk("%c %c %c %c\n",buf[0],buf[1],buf[2],buf[3]);
	/**/
/*	buf[0] = 1;
	buf[1] = 1;
	buf[2] = 1;
	buf[3] = 1;
*/
	copy_to_user(buffer,buf,4);

	return 0;
}

struct file_operations fop = {
	.owner = THIS_MODULE,
	.open = touch_open,
	.read = touch_read,
	.release = touch_close,
};

int __init touch_init(void){
	printk(KERN_ALERT "INIT touch_dev\nmajor 260\n");
	register_chrdev(DEV_NUM, DEV_NAME, &fop);
	return 0;
}

void __exit touch_exit(void){
	printk(KERN_ALERT "EXIT touch_dev\n");
	unregister_chrdev(DEV_NUM, DEV_NAME);
}

module_init(touch_init);
module_exit(touch_exit);
