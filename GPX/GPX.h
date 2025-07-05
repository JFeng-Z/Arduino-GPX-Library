/*
 * GPX Library -- GPX.h
 * Created by: Ryan Sutton
 *
 * Copyright (c) 2010, Ryan M Sutton
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Ryan M Sutton nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef GPX_h
#define GPX_h

#ifdef  ARDUINO
#include "WString.h"
#else
#include "../WString/WString.h"
#endif //  ARDUINO

// 'Public' Tags
// 定义与GPX文件格式相关的轨道点、航路点和路线点的标签名
#define GPX_TRKPT               "trkpt"  // 轨道点标签名
#define GPX_WPT                 "wpt"    // 航路点标签名
#define GPX_RTEPT               "rtept"  // 线路线点标签名

/**
 * GPX类用于生成和管理GPX格式的XML文件。
 * GPX是一种用于描述轨迹、航点和路线的XML格式。
 * 该类提供方法来创建GPX文件的各个部分，如元数据、轨迹点等。
 */
class GPX
{
public:
    // 构造函数
    GPX();

    // 获取GPX标签<metadata>的开头部分
    String getOpen();

    // 获取GPX标签</metadata>的结尾部分
    String getClose();

    // 获取GPX元数据部分，包括时间、边界框等信息
    String getMetaData();

    // 获取轨迹标签<trk>的开头部分
    String getTrakOpen();

    // 获取轨迹标签</trk>的结尾部分
    String getTrakClose();

    // 获取轨迹段标签<trkseg>的开头部分
    String getTrakSegOpen();

    // 获取轨迹段标签</trkseg>的结尾部分
    String getTrakSegClose();

    // 获取轨迹、航点或路线的信息标签，如名称、描述等
    String getInfo();

    // 根据类型、经度和纬度生成轨迹点、航点或路线点
    String getPt(String typ, String lon, String lat);

    // 根据类型、经度、纬度和海拔生成轨迹点、航点或路线点
    String getPt(String typ, String lon, String lat, String ele);

    // 设置元数据中的名称
    void setMetaName(String name);

    // 设置元数据中的描述
    void setMetaDesc(String desc);

    // 设置轨迹、航点或路线的名称
    void setName(String name);

    // 设置轨迹、航点或路线的描述
    void setDesc(String desc);

    // 设置轨迹点、航点或路线点的海拔
    void setEle(String ele);

    // 设置轨迹点、航点或路线点的符号
    void setSym(String sym);

    // 设置GPX数据的来源
    void setSrc(String src);

    // 设置时间戳
    void setTime(String time);

    // 设置速度
    void setSpeed(String speed);

private:
    //Variables
    String _metaName;
    String _metaDesc;
    String _name;
    String _desc;
    String _ele;
    String _sym;
    String _src;
    String _time;
    String _speed;

    // Functions
    // 使用CDATA封装输入字符串，以确保XML的正确性
    String wrapCDATA(String input);
};

#endif

