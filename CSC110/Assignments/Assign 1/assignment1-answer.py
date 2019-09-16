# assignment1.py
#
# Student name:
# Student id:  V00

def main():
   print("Welcome")
   print()
   # You will call your functions here to test them:
   # print_cat()
   # print_toad()
   print_logo()
   cal_surface_area()



# DEFINE your functions after this line:

def print_cat():
	print('| /\\_/\\ |')
	print('| >^.^< |')
	print('|  / \\  |')
	print('| (|_|)~|')

def print_toad():
	print('|  @ @  |')
	print('| (---) |')
	print('|( > < )|')
	print('|""   ""|')

def print_logo():
	print("/-------\\")
	print_toad()
	print("/-------\\")
	print_cat()
	print("/-------\\")
	print_toad()
	print("/-------\\")
	print_cat()
	print("/-------\\")
	print("/-------\\")

def cal_surface_area():
	PI = 3.14
	diameter = 5
	height = 6
	circumference = PI*diameter
	top_area = PI*(diameter/2)**2
	wall_area = height*circumference
	sum_area = top_area*2+wall_area
	print(sum_area)





# The following code will call your main function
# It also allows our grading script to call your main
# DO NOT ADD OR CHANGE ANYTHING PAST THIS LINE
# DOING SO WILL RESULT IN A ZERO GRADE
if __name__ == '__main__':
   main()
