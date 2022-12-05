#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Dec  1 16:26:59 2022

@author: alexpong
"""
import cv2
import os
os.environ["OPENCV_FFMPEG_CAPTURE_OPTIONS"] = "rtsp_transport;udp"

cap = cv2.VideoCapture("rtsp://192.168.0.102:8554/live?resolution=1920x960", cv2.CAP_FFMPEG)

while(True):
    ret, frame = cap.read()
    print(frame)
    cv2.imshow('frame',frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
