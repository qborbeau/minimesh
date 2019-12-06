#include <memory>
#include <vtkSmartPointer.h>

#include <vtkActor.h>
#include <vtkDataSetMapper.h>
#include <vtkDataSet.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>

#include "viewer.hpp"

void Viewer::view(vtkSmartPointer<vtkDataSet> dataset)
{
  auto mapper = vtkSmartPointer<vtkDataSetMapper>::New();
  mapper->SetInputData(dataset);

  auto actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
  actor->GetProperty()->EdgeVisibilityOn();

  auto renderer = vtkSmartPointer<vtkRenderer>::New();
  renderer->AddActor(actor);

  auto window = vtkSmartPointer<vtkRenderWindow>::New();
  window->AddRenderer(renderer);
  window->SetSize(1000,600);

  auto interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
  interactor->SetRenderWindow(window);

  window->Render();
  interactor->Start();

  // return EXIT_SUCCESS;
}
