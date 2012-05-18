IMAGE=IPDSnelting.jpg

all: SkinDetect.x10 imgdata
	x10firm -o SkinDetect SkinDetect.x10 ImageData.x10 image_data.o

imgdata: $(IMAGE)
	$(shell ./img2x10.py $(IMAGE))
