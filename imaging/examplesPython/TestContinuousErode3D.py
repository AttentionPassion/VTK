#!/usr/local/bin/python

from vtkpython import *
from WindowLevelInterface import *

# Min of sphere around every pixel.


# Image pipeline

reader = vtkImageReader()
reader.ReleaseDataFlagOff()
reader.SetDataByteOrderToLittleEndian()
reader.SetDataExtent(0,255,0,255,1,93)
reader.SetFilePrefix("../../../vtkdata/fullHead/headsq")
reader.SetDataMask(0x7fff)
#reader.DebugOn()

erode = vtkImageContinuousErode3D()
erode.SetInput(reader.GetOutput())
erode.SetKernelSize(5,5,5)

viewer = vtkImageViewer()
viewer.SetInput(erode.GetOutput())
viewer.SetZSlice(22)
viewer.SetColorWindow(2000)
viewer.SetColorLevel(1000)
#viewer.DebugOn()


WindowLevelInterface(viewer)
