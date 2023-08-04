import qrcode

qr = input("Enter The Link or Words You Want To Convert To Qrcode:\n")
img = qrcode.make(qr)

img.show()
img.save("qr.png")