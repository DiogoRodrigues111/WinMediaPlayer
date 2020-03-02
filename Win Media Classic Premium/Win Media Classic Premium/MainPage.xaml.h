//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "pch.h"
#include "MainPage.g.h"

using namespace Windows::Storage;
using namespace Windows::Storage::Pickers;

namespace Win_Media_Classic_Premium
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		void WinButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Button_Set_File_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void GetConnectionAddr(Platform::String^ addr);
		void OnLoaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void DragEnter(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e);
		void DragLeave(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e);
		void DragOver(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e);
		void DragStarting(Windows::UI::Xaml::UIElement^ sender, Windows::UI::Xaml::DragStartingEventArgs^ args);
		void Drop(Platform::Object^ sender, Windows::UI::Xaml::DragEventArgs^ e);
		void DropCompleted(Windows::UI::Xaml::UIElement^ sender, Windows::UI::Xaml::DropCompletedEventArgs^ args);

	private:
		FileOpenPicker^ pick;
		bool isDrag= false;
	};
}
