//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"

#ifdef __cplusplus
#include "MainPage.xaml.h"
#include <experimental/resumable>

using namespace Win_Media_Classic_Premium;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Media::Core;
using namespace Windows::Media::Editing;
using namespace Windows::Storage;
using namespace Windows::Storage::Pickers;
using namespace Windows::Storage::Streams;
using namespace Windows::ApplicationModel::DataTransfer;
using namespace concurrency;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

void Win_Media_Classic_Premium::MainPage::GetConnectionAddr(Platform::String^ addr) {
	
}

MainPage::MainPage()
{
	InitializeComponent();
	mediaElement->AllowDrop = true;
}


void MainPage::WinButton_Click(Object^ sender, RoutedEventArgs^ e)
{

}

template< typename TReturn >
task< TReturn > 
__declspec (noinline)
createTask (
	const task< TReturn >& _task )
{
	task< TReturn > _Creation( _task );
	return _Creation;
}

template< typename TReturn >
task< TReturn > 
__declspec (noinline)
createTaskAsync (
	TReturn ^_TReturn,
	Windows::Foundation::IAsyncOperation<TReturn>^ _pTask)
{
	task< TReturn > _Creation(_task);
	return _Creation;
}

void MainPage::Button_Set_File_Click(Object^ sender, RoutedEventArgs^ e)
{
	pick = ref new FileOpenPicker();
	pick->SuggestedStartLocation = PickerLocationId::VideosLibrary;
	pick->FileTypeFilter->Append(".mp4");
	pick->FileTypeFilter->Append(".mp3");
	pick->FileTypeFilter->Append("*");

	//mediaElement->CurrentState = MediaElementState::Playing;
	//if(mediaElement->CurrentState == MediaElementState::Playing)
	if (mediaElement->CompositeMode == ElementCompositeMode::MinBlend) {
		return;
	}

	createTaskAsync(pick->PickSingleFileAsync()).then([&, this](StorageFile ^fileStorage) {
		if (pick == nullptr) {
			return;
		}

		if(pick != nullptr) {
			
		}
		
		Windows::Storage::StorageFile^ storage = fileStorage;

		createTaskAsync(fileStorage->OpenReadAsync()).then(
			[=, this](IRandomAccessStreamWithContentType^ random_video) {
			mediaElement->SetSource(random_video, storage->ContentType);
		});
	});

}


void Win_Media_Classic_Premium::MainPage::OnLoaded(Platform::Object^ sender,
												   Windows::UI::Xaml::RoutedEventArgs^ e)
{
	
}


void Win_Media_Classic_Premium::MainPage::DragEnter(Platform::Object^ sender,
													Windows::UI::Xaml::DragEventArgs^ e)
{
	isDrag = true;
}


void Win_Media_Classic_Premium::MainPage::DragLeave(Platform::Object^ sender,
													Windows::UI::Xaml::DragEventArgs^ e)
{
	isDrag = false;
}


void Win_Media_Classic_Premium::MainPage::DragOver(Platform::Object^ sender,
												   Windows::UI::Xaml::DragEventArgs^ e)
{
	/*
	create_task([=](DataPackage^ data) {
		e->Data->SetStorageItems();

	});//Windows::ApplicationModel::DataTransfer::DataPackager ^data
	*/
	e->AcceptedOperation = DataPackageOperation::Copy;
}


void Win_Media_Classic_Premium::MainPage::DragStarting(Windows::UI::Xaml::UIElement^ sender,
													   Windows::UI::Xaml::DragStartingEventArgs^ args)
{

}


void Win_Media_Classic_Premium::MainPage::Drop(Platform::Object^ sender,
											   Windows::UI::Xaml::DragEventArgs^ e)
{
	if (e->DataView->Contains(StandardDataFormats::StorageItems)) {
		StorageFile^ items = (StorageFile^)e->DataView->GetStorageItemsAsync();
		//StorageFile ^storage = items[0];
		mediaElement->SetSource((IRandomAccessStream^)items->OpenAsync(FileAccessMode::Read), nullptr);
	}
}


void Win_Media_Classic_Premium::MainPage::DropCompleted(Windows::UI::Xaml::UIElement^ sender,
														Windows::UI::Xaml::DropCompletedEventArgs^ args)
{
	
}

#endif
