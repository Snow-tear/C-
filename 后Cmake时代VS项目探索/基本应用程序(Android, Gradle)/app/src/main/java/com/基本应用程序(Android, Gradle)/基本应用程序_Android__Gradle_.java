
package com.基本应用程序_Android__Gradle_;

import android.app.Activity;
import android.widget.TextView;
import android.os.Bundle;

public class 基本应用程序_Android__Gradle_ extends Activity
{
    /** 在首次创建活动时调用。 */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        /* 创建一个 TextView，并将其文本设置为 "Hello world" */
        TextView  tv = new TextView(this);
        tv.setText("Hello World!");
        setContentView(tv);
    }
}
