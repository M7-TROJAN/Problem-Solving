import qrcode

qr = input("Enter The Link or Words You Want To Convert To Qrcode:\n")
img = qrcode.make(qr)


pic_name = input("Enter The Name You Want TO Save The Picture with it:\n")
img.save(f"pictures/{pic_name}.png")