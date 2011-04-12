/*=========================================================================

 Program:   Visualization Toolkit
 Module:    vtkAMREnzoReader.h

 Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
 All rights reserved.
 See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

 This software is distributed WITHOUT ANY WARRANTY; without even
 the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE.  See the above copyright notice for more information.

 =========================================================================*/
// .NAME vtkAMREnzoReader.h -- Reader for Enzo AMR datasets.
//
// .SECTION Description
// A concrete instance of vtkAMRBaseReader that implements functionality
// for reading Enzo AMR datasets.

#ifndef VTKAMRENZOREADER_H_
#define VTKAMRENZOREADER_H_

#include "vtkAMRBaseReader.h"

class vtkHierarchicalBoxDataSet;
class vtkEnzoReaderInternal;

class VTK_AMR_EXPORT vtkAMREnzoReader : public vtkAMRBaseReader
{
  public:
    static vtkAMREnzoReader* New();
    vtkTypeMacro(vtkAMREnzoReader,vtkAMRBaseReader);
    void PrintSelf(std::ostream &os, vtkIndent indent );

    // Description:
    // See vtkAMRBaseReader::SetFileName
    void SetFileName( const char* fileName );

  protected:
    vtkAMREnzoReader();
    ~vtkAMREnzoReader();

    // Description:
    // See vtkAMRBaseReader::ReadMetaData
    void ReadMetaData();

    // Description:
    // See vtkAMRBaseReader::GenerateBlockMap
    void GenerateBlockMap();

    // Description:
    // See vtkAMRBaseReader::GetBlockLevel
    int GetBlockLevel( const int blockIdx );

    // Description:
    // See vtkAMRBaseReader::GetNumberOfBlocks
    int GetNumberOfBlocks();

    // Description:
    // See vtkAMRBaseReader::GetNumberOfLevels
    int GetNumberOfLevels();

    // Description:
    // See vtkAMRBaseReader::GetBlock
    void GetBlock(
        int index, vtkHierarchicalBoxDataSet *hbds,
        vtkstd::vector< int > &idxcounter);

    // Description:
    // See vtkAMRBaseReader::SetUpDataArraySelections
    void SetUpDataArraySelections();

  private:
    vtkAMREnzoReader( const vtkAMREnzoReader& ); // Not Implemented
    void operator=(const vtkAMREnzoReader& ); // Not Implemented

    vtkEnzoReaderInternal *Internal;
};

#endif /* VTKAMRENZOREADER_H_ */
