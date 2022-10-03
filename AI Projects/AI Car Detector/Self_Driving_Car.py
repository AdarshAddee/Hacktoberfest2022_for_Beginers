#importing open computer vision!
import cv2

#Test video
img_file = './assets/car1.avi'

#trained detection algorithm
bus_classifier = cv2.CascadeClassifier('bus.xml')
car_classifier = cv2.CascadeClassifier('cars.xml')
pedestrian_classifier = cv2.CascadeClassifier('pedestrian.xml')
bike_classifier = cv2.CascadeClassifier('bike.xml')

#giving the image to openCV
vid = cv2.VideoCapture(img_file)

#run until the car turns off or crashes and burns to ashes
while True:
    #gives a touple
    (frame_read,frame) = vid.read()  

    if frame_read:
        #convert the image to garyscale
        gimg = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)

        #Detect the everything with their respective algorithms
        pedestrians = pedestrian_classifier.detectMultiScale(gimg)
        cars = car_classifier.detectMultiScale(gimg)
        bike = bike_classifier.detectMultiScale(gimg)
        bus = bus_classifier.detectMultiScale(gimg)


        #Display the detection
        for(x,y,w,h) in cars:
             cv2.rectangle(frame,(x,y),(x+w,y+h),(0,255,0),4)
        #Display the detection
        for(x,y,w,h) in bus:
             cv2.rectangle(frame,(x,y),(x+w,y+h),(0,0,225),4)
        for(x,y,w,h) in bike:
             cv2.rectangle(frame,(x,y),(x+w,y+h),(255,0,0),4) 
        #Display the detection
        for(x,y,w,h) in pedestrians:
             cv2.rectangle(frame,(x,y),(x+w,y+h),(69,125,23),4)

            #display image
        cv2.imshow("Sasta Tesla Sofware XD",frame)
        cv2.waitKey(1)
    else:
        print("Error in reading the frames")
        break
print("Code Completed 👑")