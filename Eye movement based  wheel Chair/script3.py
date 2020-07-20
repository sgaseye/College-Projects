import cv2
import serial
from gaze_tracking import GazeTracking

gaze = GazeTracking()
webcam = cv2.VideoCapture(0)
#ser = serial.Serial('COM3', 9600)

while True:
    # We get a new frame from the webcam
    _, frame = webcam.read()

    # We send this frame to GazeTracking to analyze it
    gaze.refresh(frame)

    frame = gaze.annotated_frame()
    text = ""

    if gaze.is_blinking():
        text = "Down"
        #ser.write(b'B')
    elif gaze.is_right():
        text = "Right"
        #ser.write(b'R')
    elif gaze.is_left():
        text = "Left"
        #ser.write(b'L')
    elif gaze.is_up():
        text = "Up"
        ser.write(b'F')
    elif gaze.is_center():
        text = "Center"
        #ser.write(b'S')
       
    cv2.putText(frame, text, (90, 60), cv2.FONT_HERSHEY_DUPLEX, 1.6, (0, 0, 255), 2)

    cv2.imshow("Eye Tracking", frame)

    if cv2.waitKey(1) == 27:
        break
