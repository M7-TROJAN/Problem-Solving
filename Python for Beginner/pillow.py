from PIL import Image , ImageFilter

image_path = Image.open("your image path here ")   #ex  photo/image.jpg

image_path.show() 

new = image_path.filter(ImageFilter.BoxBlur(5))

new.save("new.png")
new.show()