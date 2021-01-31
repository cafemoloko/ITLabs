# Dokończenie zadania, które rozpoczęliśmy na zajęciach. 
# Obraz RGB jest dzielony na 3 warstwy. Dla każdej obliczana jest średnia wartość
# sąsiadujących pikseli, co po ponownym połączeniu, daje efekt rozmycia.


from PIL import Image
import numpy as np

def chunks(lst, n):
    # Yield successive n-sized chunks from list.
    for i in range(0, len(lst), n):
        yield lst[i:i + n]

def split_layer(rgb_image):
    # Splits layers to three separate lists
    r = list(rgb_image[0].getdata())
    g = list(rgb_image[1].getdata())
    b = list(rgb_image[2].getdata())
    return r, g, b

def count_pixel_mean(rgb_layer):
    # Counts mean value for every pixel, using values of sourrounding pixels
    mean_layer = []
    for x in range(1, im.height-1):
        for y in range(1, im.width-1):
            mean_pixel = (rgb_layer[x-1][y-1] + rgb_layer[x-1][y] + rgb_layer[x-1][y+1] 
                         + rgb_layer[x][y-1] + rgb_layer[x][y] + rgb_layer[x][y + 1] 
                         + rgb_layer[x+1][y-1] + rgb_layer[x+1][y] + rgb_layer[x+1][y+1]) // 9
            mean_layer.append(mean_pixel)
    return mean_layer

if __name__ == '__main__':

    # Load and show original image
    im = Image.open("parrots.jpg")
    im.show() 

    # Split image to three layers
    RGB = im.split()
    red_layer, green_layer, blue_layer = split_layer(RGB)

    # Convert layers to lists and chunk them
    red_layer = list(chunks(red_layer, im.width))
    green_layer = list(chunks(green_layer, im.width))
    blue_layer = list(chunks(blue_layer, im.width))
  
    # Applying blur filer for layers 
    red_layer_mean = count_pixel_mean(red_layer)
    green_layer_mean = count_pixel_mean(green_layer)
    blue_layer_mean = count_pixel_mean(blue_layer)

    # Convert layers to numpy array and reshape them
    # Note! Image has 2px less height and width due to blur filter implementation
    arr_r = np.array(red_layer_mean, dtype=np.uint8).reshape(-1, im.width-2)
    arr_g = np.array(green_layer_mean, dtype=np.uint8).reshape(-1, im.width-2)
    arr_b = np.array(blue_layer_mean, dtype=np.uint8).reshape(-1, im.width-2)

    # Convert layers to pillow object
    r = Image.fromarray(arr_r)
    g = Image.fromarray(arr_g)
    b = Image.fromarray(arr_b)

    # Merge layers, save and show blurred image
    blurred_rgb_image = Image.merge('RGB', (r, g, b))
    blurred_rgb_image.save("parrots_blurred.jpg")
    blurred_rgb_image.show()



