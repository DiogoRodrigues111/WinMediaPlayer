//
// media.xaml.h
// Declaration of the media class
//

#pragma once

#include "media.g.h"

namespace Win_Media_Classic_Premium
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class media sealed
	{
	public:
		media();
	private:
		void button_chooser_music_data_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void button_chooser_video_data_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
