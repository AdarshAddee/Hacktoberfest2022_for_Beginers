/* jQuery based image slider
/* TMSlider 0.4.1 */
;(function($){
	$.fn.TMSlider=$.fn.TMS=$.fn._TMS=function(o){
		return this.each(function(){
			var th=$(this),				
				_=th.data('_TMS')||{
					presets:{
						centralExpand:{"reverseWay":false,"interval":80,"blocksX":8,"blocksY":4,"easing":"easeInQuad","way":"diagonal","anim":"centralExpand"},
						zoomer:{"reverseWay":false,"interval":"1","blocksX":"1","blocksY":"1","easing":"","way":"lines","anim":"zoomer"},
						fadeThree:{"reverseWay":false,"interval":"1","blocksX":"1","blocksY":"1","easing":"","way":"lines","anim":"fadeThree"},
						simpleFade:{"reverseWay":false,"interval":"1","blocksX":"1","blocksY":"1","easing":"","way":"lines","anim":"fade"},
						gSlider:{"reverseWay":false,"interval":40,"blocksX":"1","blocksY":"1","easing":"","way":"lines","anim":"gSlider"},
						vSlider:{"reverseWay":false,"interval":40,"blocksX":"1","blocksY":"1","easing":"","way":"lines","anim":"vSlider"},
						slideFromLeft:{"reverseWay":false,"interval":"1","blocksX":"1","blocksY":"1","easing":"easeOutBack","way":"lines","anim":"slideFromLeft"},
						slideFromTop:{"reverseWay":false,"interval":"1","blocksX":"1","blocksY":"1","easing":"easeOutBack","way":"lines","anim":"slideFromTop"},
						diagonalFade:{"reverseWay":false,"interval":40,"blocksX":12,"blocksY":6,"easing":"easeInQuad","way":"diagonal","anim":"fade"},
						diagonalExpand:{"reverseWay":false,"interval":40,"blocksX":8,"blocksY":4,"easing":"easeInQuad","way":"diagonal","anim":"expand"},
						fadeFromCenter:{"reverseWay":true,"interval":"10","blocksX":"10","blocksY":"6","easing":"","way":"spiral","anim":"fade"},
						zabor:{"reverseWay":false,"interval":40,"blocksX":"20","blocksY":"1","easing":"","way":"lines","anim":"slideRight"},
						vertivalLines:{"reverseWay":false,"interval":1,"blocksX":12,"blocksY":1,"easing":"swing","way":"lines","anim":"vSlideOdd"},
						gorizontalLines:{"reverseWay":false,"interval":1,"blocksX":1,"blocksY":12,"easing":"swing","way":"lines","anim":"gSlideOdd"},
						random:{prsts:['centralExpand','fadeThree','simpleFade','gSlider','vSlider','slideFromLeft','slideFromTop','diagonalFade','diagonalExpand','fadeFromCenter','zabor','vertivalLines','gorizontalLines']}
					},
					ways: {				
						lines: function () {
							var opt=this
							for (var ret = [], i = 0; i < opt.maskC.length; i++)
								ret.push(opt.maskC.eq(i))
							return ret
						},
						spiral: function () {
							var opt=this,
								ret = [],
								step = 0,
								h = opt.blocksY,
								w = opt.blocksX,
								x, y, i, lr = function () {
									for (i = step; i < w - 1 - step; i++)
									if (ret.length < opt.maskC.length) ret.push(opt.matrix[step][i])
									else return false
									rb()
								},
								rb = function () {
									for (i = step; i < h - 1 - step; i++)
									if (ret.length < opt.maskC.length) ret.push(opt.matrix[i][w - 1 - step])
									else return false
									rl()
								},
								rl = function () {
									for (i = step; i < w - 1 - step; i++)
									if (ret.length < opt.maskC.length) ret.push(opt.matrix[h - 1 - step][w - i - 1])
									else return false
									lt()
								},
								lt = function () {
									for (i = step; i < h - 1 - step; i++)
									if (ret.length < opt.maskC.length) ret.push(opt.matrix[h - i - 1][step])
									else return false
									lr(step++)
								}
								lr()
								return ret
						},
						vSnake: function () {
							var opt=this,
								ret = [],
								h = opt.blocksY,
								w = opt.blocksX,
								j, i
								for (i = 0; i < w; i++)
								for (j = 0; j < h; j++)
								if (i * .5 == ~~ (i / 2)) ret.push(opt.matrix[j][i])
								else ret.push(opt.matrix[h - 1 - j][i])
								return ret
						},
						gSnake: function () {
							var opt=this,
								ret = [],
								h = opt.blocksY,
								w = opt.blocksX,
								j, i
								for (i = 0; i < h; i++)
								for (j = 0; j < w; j++)
								if (i * .5 == ~~ (i / 2)) ret.push(opt.matrix[i][j])
								else ret.push(opt.matrix[i][w - 1 - j])
								return ret
						},
						diagonal: function () {
							var opt=this,
								ret = [],
								h = opt.blocksY,
								w = opt.blocksX,
								i = j = n = 0
							for (i = 0; i < w; i++)
								for (ret[i] = [], j = 0; j <= i; j++)
									if (j < h) ret[i].push(opt.matrix[j][i - j])
										for (i = 1; i < h; i++)
											for (j = 0, ret[n = ret.length] = []; j < h - i; j++)
												ret[n].push(opt.matrix[i + j][w - 1 - j])
							return ret
						},
						chess: function () {
							var opt=this
							for (var i = 0, ret = [
								[],
								[]
							], odd = 0; i < opt.maskC.length; i++)
							ret[odd = odd ? 0 : 1].push(opt.maskC.eq(i))
							return ret
						},
						randomly: function () {
							var opt=this
							for (var ret = [], n = i = 0; i < opt.maskC.length; i++)
							ret.push(opt.maskC.eq(i))
							for (i = 0; i < opt.maskC.length; i++)
							ret.push(ret.splice(parseInt(Math.random() * opt.maskC.length - 1), 1)[0])
							return ret
						}
					},

					anims: {			
						centralExpand:function(el,last){				
							$(el).each(function(){
								var th=$(this).css({visibility:'hidden'}),
									x=th.show().prop('offsetLeft'),
									y=th.show().prop('offsetTop'),
									w=th.width(),
									h=th.height()
														
								th
									.stop()
									.css({
										left:x+w/2,
										top:y+h/2,
										width:0,
										height:0,
										visibility:'visible',
										opacity:0
									})
									.animate({
										width:w//,
										// height:h,
										// left:x,
										// top:y
									},{
										step:function(now){
											var pc=(1-(w-now)/100)								
											th
												.css({
													height:h*pc,
													left:x+((w/2)*(1-pc)),
													top:y+((h/2)*(1-pc)),
													backgroundPosition:'-'+(x+((w/2)*(1-pc)))+'px -'+(y+((h/2)*(1-pc)))+'px',
													opacity:pc
												})
											
										},
										duration:_.duration,
										easing:_.easing,
										complete:function(){
											if(last)_.afterShow()
										}
									})
							})
						},			
						fadeThree:function(el,last){
							var _=this
							$(el).each(function(i){
								var th=$(this).show().css({left:-_.width/4,top:0,zIndex:2,opacity:0}),
									clone=th.clone().appendTo(th.parent()).css({left:_.width/4,top:_.height/4,zIndex:1}),
									clone2=th.clone().appendTo(th.parent()).css({left:0,top:-_.height/4,zIndex:1})
								//console.log(_.duration)	
								clone
									.stop()
									.animate({
										left:0,
										top:0,
										opacity:1
									},{
										duration:_.duration,
										easing:_.easing
									})
								clone2
									.stop()
									.animate({
										left:0,
										top:0,
										opacity:1
									},{
										duration:_.duration,
										easing:_.easing
									})
								th	
									.stop()
									.animate({
										left:0,
										top:0,
										opacity:1
									},{
										duration:_.duration,
										easing:_.easing,							
										complete:function(){
											if(last)_.afterShow()
											clone.remove()
											clone2.remove()
										}
									})
							})
						},
						zoomer:function(el,last){
							if(_.slideshow)
								_.slideshow=_.duration-2000
							
							el.each(function(){
								var src=_.next
								,ie=$.browser.msie&&$.browser.version<9
								,buff=$(new Image())
								,canvas=ie?$(new Image()):$('<canvas></canvas>')
								,width,height
								,duration=_.duration
								,k=_.presetParam.k||1.2
								,holder=_.pic
								,wrap=$('<div></div>')
									.css({
										position:'absolute'
										,left:0
										,top:0
										,zIndex:10
										,width:holder.width()
										,height:holder.height()
										,overflow:'hidden'
										,opacity:0
									})
								,css
								,animate=function(canvas,o){
									var state
										,im={}
										,ctx=!ie&&canvas[0].getContext('2d')
										,state=0
										,step=1/duration*40
										,refresh=function(state){
											ie
												?canvas.css({
													left:o.start.left+(o.finish.left-o.start.left)*state
													,top:o.start.top+(o.finish.top-o.start.top)*state
													,width:o.start.width+(o.finish.width-o.start.width)*state
													,height:o.start.height+(o.finish.height-o.start.height)*state
												})
												:ctx.drawImage(buff[0],
													im.left=o.start.left+(o.finish.left-o.start.left)*state,
													im.top=o.start.top+(o.finish.top-o.start.top)*state,
													im.width=o.start.width+(o.finish.width-o.start.width)*state,
													im.height=o.start.height+(o.finish.height-o.start.height)*state)
										}
									refresh(0)
									clearInterval(_.int)
									_.int=setInterval(function(){
										if(_.paused)
											return false
										if(state>=1){
											clearInterval(_.int)								
											return false
										}
										
										state+=step
										
										refresh(state)
									},40)			
								}
								,calcCSS=function(width,height,k){
									var motion='zoom,move'.split(',')[~~(Math.random()*2)]		
										,side='left,right,top,bottom,leftTop,leftBottom,center'.split(',')[~~(Math.random()*7)]
										,reverse=[false,true][~~(Math.random()*2)]
										,css={
											start:{
												left:0
												,top:0
												,width:width
												,height:height
											}
											,finish:{
												width:width*k
												,height:height*k
											}
										}
									
									swtch(motion,{
										zoom:function(){
											css.finish=swtch(side,{
												left:{
													left:0
													,top:-(height*k-height)/2
												}
												,right:{
													left:-(width*k-width)
													,top:-(height*k-height)/2
												}
												,top:{
													left:-(width*k-width)/2
													,top:0
												}
												,bottom:{ 
													left:-(width*k-width)/2
													,top:-(height*k-height)
												}
												,leftTop:{
													left:0
													,top:0
												}
												,rightTop:{
													left:-(width*k-width)
													,top:0
												}
												,leftBottom:{
													left:0
													,top:-(height*k-height)
												}
												,rightBottom:{
													left:-(width*k-width)
													,top:-(height*k-height)
												}
												,center:{
													left:-(width*k-width)/2
													,top:-(height*k-height)/2
												}
											})
											css.finish.width=width*k
											css.finish.height=height*k			
										}
										,move:function(){
											css=$.extend(true,css,side!='center'?{start:{width:width*k,height:height*k}}:{})
											
											css=$.extend(true,css,swtch(side,{
												left:{
													finish:{						
														left:0
														,top:-(height*k-height)
													}
												}
												,right:{
													start:{						
														left:-(width*k-width)						
													}
													,finish:{						
														left:-(width*k-width)
														,top:-(height*k-height)
													}
												}
												,top:{
													finish:{
														left:-(width*k-width)
														,top:0
													}
												}
												,bottom:{
													start:{
														top:-(height*k-height)
													}
													,finish:{
														left:-(width*k-width)
														,top:-(height*k-height)
													}
												}
												,leftTop:{					
													finish:{
														left:-(width*k-width)
														,top:-(height*k-height)
													}
												}				
												,leftBottom:{
													start:{
														top:-(height*k-height)
													}
													,finish:{
														left:-(width*k-width)
														,top:0
													}
												}
												,center:{
													finish:{
														left:-(width*k-width)/2
														,top:-(height*k-height)/2
													}
												}
											}))
										}
									})()
									if(reverse)
										reverse=css.start,
										css.start=css.finish,
										css.finish=reverse
									return css
								}
							buff
								.css({			
									left:'-999%'
									,top:'-999%'
									,position:'absolute'
								})
								.appendTo('body')
								.load(function(){
									width=buff.width()
									height=buff.height()
									
									if(!ie)
										canvas
											.appendTo(wrap.appendTo(holder))
											.attr({
												width:holder.width()
												,height:holder.height()
											})
									else
										canvas=buff
											.css({
												position:'absolute'
												,left:0
												,top:0
												,zIndex:1
											})
											.appendTo(wrap.appendTo(holder))
									_.afterShow()
									_.bl=true
									wrap
										.stop()							
										.animate({
											opacity:1
										},{
											duration:_.presetParam.crossFadeDur||2000
											,complete:function(){									
												// console.log(holder)
												// holder.children()
													// .not(wrap)
												
														// .remove()
											}
										})
									$.when(wrap)
										.then(function(){
											_.bl=false
											holder.children()
												.not(wrap)
													.remove()
										})
									animate(canvas,calcCSS(width,height,k))
									!ie&&buff.detach()
								})
								.attr({src:src})
							})
						},
						fade: function (el, last) {
							var opt=this
							$(el).each(function () {
								$(this).css({
									opacity: 0
								}).show().stop().animate({
									opacity: 1
								}, {
									duration: +opt.duration,
									easing: opt.easing,
									complete: function () {
										if (last) opt.afterShow()
									}
								})
							})
						},		
						expand: function (el, last) {
							var opt=this
							$(el).each(function () {
								$(this).hide().show(+opt.duration, function () {
									if (last) opt.afterShow()
								})
							})
						},
						slideDown: function (el, last) {
							var opt=this
							$(el).each(function () {
								var th = $(this).show(),
									h = th.height()
									th.css({
										height: 0
									}).stop().animate({
										height: h
									}, {
										duration: opt.duration,
										easing: opt.easing,
										complete: function () {
											if (last) opt.afterShow()
										}
									})
							})
						},
						slideLeft: function (el, last) {
							var opt=this
							$(el).each(function () {
								var th = $(this).show(),
									w = th.width()
									th.css({
										width: 0
									}).stop().animate({
										width: w
									}, {
										duration: opt.duration,
										easing: opt.easing,
										complete: function () {
											if (last) opt.afterShow()
										}
									})
							})
						},
						slideUp: function (el, last) {
							var opt=this
							$(el).each(function () {
								var th = $(this).show(),
									h = th.height(),
									l = th.attr('offsetLeft'),
									t = th.attr('offsetTop')
									th.css({
										height: 0,
										top: t + h
									}).stop().animate({
										height: h
									}, {
										duration: opt.duration,
										easing: opt.easing,
										step: function (now) {
											var top = t + h - now
											th.css({
												top: top,
												backgroundPosition: '-' + l + 'px -' + top + 'px'
											})
										},
										complete: function () {
											if (last) opt.afterShow()
										}
									})
							})
						},
						slideRight: function (el, last) {
							var opt=this
							$(el).each(function () {
								var th = $(this).show(),
									w = th.width(),
									l = th.attr('offsetLeft'),
									t = th.attr('offsetTop')
									th.css({
										width: 0,
										left: l + w
									}).stop().animate({
										width: w
									}, {
										duration: opt.duration,
										easing: opt.easing,
										step: function (now) {
											var left = l + w - now
											th.css({
												left: left,
												backgroundPosition: '-' + left + 'px -' + t + 'px'
											})
										},
										complete: function () {
											if (last) opt.afterShow()
										}
									})
							})
						},
						slideFromTop: function (el, last) {
							var opt=this
							$(el).each(function () {
								var th = $(this),
									t = th.show().css('top'),
									h = th.height()
									th.css({
										top: -h
									}).stop().animate({
										top: t
									}, {
										duration: +opt.duration,
										easing: opt.easing,
										complete: function () {
											if (last) opt.afterShow()
										}
									})
							})
						},
						slideFromDown: function (el, last) {
							var opt=this
							$(el).each(function () {
								var th = $(this),
									t = th.show().css('top'),
									h = th.height()
									th.css({
										top: h
									}).stop().animate({
										top: t
									}, {
										duration: +opt.duration,
										easing: opt.easing,
										complete: function () {
											if (last) opt.afterShow()
										}
									})
							})
						},
						slideFromLeft: function (el, last) {
							var opt=this
							$(el).each(function () {
								var th = $(this),
									l = th.show().css('left'),
									w = th.width()
									th.css({
										left: -w
									}).stop().animate({
										left: l
									}, {
										duration: +opt.duration,
										easing: opt.easing,
										complete: function () {
											if (last) opt.afterShow()
										}
									})
							})
						},
						slideFromRight: function (el, last) {
							var opt=this
							$(el).each(function () {
								var th = $(this),
									l = th.show().css('left'),
									w = th.width()
									th.css({
										left: w
									}).stop().animate({
										left: l
									}, {
										duration: +opt.duration,
										easing: opt.easing,
										complete: function () {
											if (last) opt.afterShow()
										}
									})
							})
						},			
						gSlider: function (el, last) {
							var opt=this,
								clone = opt.maskC.clone(),
								w = clone.width()
								clone.appendTo(opt.maskC.parent()).css({
									background: opt.pic.css('backgroundImage')
								}).show()
								el.show().css({
									left: opt.direction > 0 ? -w : w
								}).stop().animate({
									left: 0
								}, {
									duration: +opt.duration,
									easing: opt.easing,
									step: function (now) {
										if (opt.direction > 0) clone.css('left', now + w)
										else clone.css('left', now - w)
									},
									complete: function () {
										clone.remove()
										if (last) opt.afterShow()
									}
								})
						},
						vSlider: function (el, last) {
							var opt=this,
								clone = opt.maskC.clone(),
								h = clone.height()
								clone.appendTo(opt.maskC.parent()).css({
									background: opt.pic.css('backgroundImage')
								}).show()
								el.show().css({
									top: opt.direction > 0 ? -h : h
								}).stop().animate({
									top: 0
								}, {
									duration: +opt.duration,
									easing: opt.easing,
									step: function (now) {
										if (opt.direction > 0) clone.css('top', now + h)
										else clone.css('top', now - h)
									},
									complete: function () {
										clone.remove()
										if (last) opt.afterShow()
									}
								})
						},
						vSlideOdd: function (el, last) {
							 var opt=this
							$(el).each(function () {
								var th = $(this),
									t = th.show().css('top'),
									h = th.height(),
									odd = opt.odd
									th.css({
										top: odd ? -h : h
									}).stop().animate({
										top: t
									}, {
										duration: +opt.duration,
										easing: opt.easing,
										complete: function () {
											if (last) opt.afterShow()
										}
									})
									opt.odd = opt.odd ? false : true

							})
						},
						gSlideOdd: function (el, last) {
							 var opt=this
							$(el).each(function () {
								var th = $(this),
									l = th.show().css('left'),
									w = th.width(),
									odd = opt.odd
									th.css({
										left: odd ? -w : w
									}).stop().animate({
										left: l
									}, {
										duration: +opt.duration,
										easing: opt.easing,
										complete: function () {
											if (last) opt.afterShow()
										}
									})
									opt.odd = opt.odd ? false : true

							})
						}
					},
						etal:'<div></div>',
						items:'.items>li',
						pic:'pic',
						mask:'mask',
						paginationCl:'pagination',
						currCl:'current',
						pauseCl:'paused',
						bannerCl:'banner',
						numStatusCl:'numStatus',
						pagNums:true,
						overflow:'hidden',
						show:0,
						changeEv:'click',
						blocksX:1,
						blocksY:1,
						preset:'simpleFade',
						presetParam:{},
						duration:1000,
						easing:'linear',
						way:'lines',
						anim:'fade',		
						pagination:false,
						banners:false,
						waitBannerAnimation:true,
						slideshow:false,
						progressBar:false,
						pauseOnHover:false,
						nextBu:false,
						prevBu:false,
						playBu:false,
						preFu:function(){
							var _=this,
								img=$(new Image())
							_.pic=$(_.etal)
								.addClass(_.pic)
								.css({overflow:_.overflow})
								.appendTo(_.me)
							_.mask=$(_.etal)
								.addClass(_.mask)
								.appendTo(_.pic)
							
							if(_.me.css('position')=='static')
								_.me.css({position:'relative'})
							if(_.me.css('z-index')=='auto')
								_.me.css({zIndex:1})
								
							_.me.css({overflow:_.overflow})
							
							if(_.items)
								_.parseImgFu()
							img
								.appendTo(_.me)
								.load(function(){
									setTimeout(function(){
										_.pic
											.css({
												width:_.width=img.width(),
												height:_.height=img.height(),
												background:_.preset=='zoomer'?'none':('url('+_.itms[_.show]+') 0 0 no-repeat')
											})
										img.remove()
										_.current=_.buff=_.show
										var t						
										if(_.preset=='zoomer')
											t=_.n
											,_.n=-1
											,_.changeFu(t)
									},1)
								})
								.attr({src:_.itms[_.n=_.show]})
						},
						sliceFu:function(w,h){
							var _=this,
								w=_.blocksX,
								h=_.blocksY,
								eW=parseInt(_.width/w),
								eH=parseInt(_.height/h),
								etal=$(_.etal),
								fW=_.pic.width()-eW*w,
								fH=_.pic.height()-eH*h,
								x,y,
								matrix=_.matrix=[]
							
							_.mask
								.css({
									position:'absolute',
									width:'100%',
									height:'100%',
									left:0,
									top:0,
									zIndex:1
								})
								.empty()
								.appendTo(_.pic)
								
							for(y=0;y<h;y++)
								for(x=0;x<w;x++)
									matrix[y]=matrix[y]?matrix[y]:[],
									matrix[y][x]=$(_.etal).clone()
										.appendTo(_.mask)
										.css({
											 left:x*eW,
											 top:y*eH,
											 position:'absolute',
											 width:x==w-1?eW+fW:eW,
											 height:y==h-1?eH+fH:eH,
											 backgroundPosition:'-'+x*eW+'px -'+y*eH+'px',
											 display:'none'
										 })
							if(_.maskC){
								_.maskC.remove()
								delete _.maskC
							}
							_.maskC=_.mask.children()			
						},
						changeFu:function(n){
							var _=this
							if(_.bl)
								return false
							
							if(n==_.n)
								return false
							_.n=n
							_.next=_.itms[n]
							_.direction=n-_.buff
							
							if(_.pagination&&_.pagination!==true&&_.pagination.data('uCarousel'))
								_.pagination.uCarousel(n)
							if(_.direction==_.itms.length-1)
								_.direction=-1
							if(_.direction==-1*_.itms.length+1)
								_.direction=2
							_.current=_.buff=n
							
							if(_.numStatus)
								_.numStatusChFu()
							
							if(_.pagination)
								_.pags
									.removeClass(_.currCl)
									.eq(n)
										.addClass(_.currCl)
							
							if(_.banners!==false&&_.banner)
								_.bannerHide(_.banner,_)
							if(_.progressBar)
								clearInterval(_.slShTimer),
								_.progressBar.stop()
							if(_.slideshow&&!_.paused&&_.progressBar)
								_.progressBar.stop().width(0)
								
							var _fu=function(){
								//if(_.banner)
									//$.when(_.banner).then(function(){_.banner.detach()})
								if($.browser.msie&&$.browser.version<9&&_.preset=='zoomer')
									_.preset='simpleFade'
									,_.duration=1000
								
								if(_.preset_!=_.preset)
									 _.du=_.duration,
									 _.ea=_.easing,
									$.extend(_,_.presets[_.preset]),
									 _.duration=_.du,
									 _.easing=_.ea,
									_.preset_=_.preset								
								if(_.preset=='random')									
									$.extend(_,_.presets[_.prsts[parseInt(Math.random()*_.prsts.length)]])
									,_.reverseWay=[true,false][parseInt(Math.random()*2)]
								
								_.sliceFu()
								_.maskC.stop().css({backgroundImage:'url('+_.next+')'})
								_.beforeAnimation()
								_.showFu()
								
							}
							if(_.waitBannerAnimation)
								$.when(_.banner).then(_fu)
							else
								_fu()
						},
						nextFu:function(){
							var _=this,
								n=_.n
							_.changeFu(++n<_.itms.length?n:0)
						},
						prevFu:function(){
							var _=this,
								n=_.n
							_.changeFu(--n>=0?n:_.itms.length-1)
						},
						showFu:function(){
							var _=this,
								way,
								tmp
							
							way=_.ways[_.way].call(_)
						
							if(_.reverseWay)
								way.reverse()
							if(_.dirMirror)
								way=_.dirMirrorFu(way)
							
							if(_.int)
								clearInterval(_.int)
							_.int=setInterval(function(){
								if(way.length)
									_.anims[_.anim].apply(_,[way.shift(),!way.length])
								else
									clearInterval(_.int)//,
									//$.when(_.maskC).then(function(){_.maskC.remove(),delete _.maskC})
								},_.interval)
							_.bl=true
						},
						dirMirrorFu:function(way){
							var _=this
							if(_.direction<0)
								void(0)
							return way
						},
						afterShow:function(){			
							var _=this
							_.pic.css({backgroundImage:'url('+_.next+')'})
							//_.pic.children().not().remove()			
							_.maskC.hide()
							if(_.slideshow&&!_.paused)
								_.startSlShFu(0)
							if(_.banners!==false)
								_.banner=_.banners[_.n]					
							if(_.banner)
								$.when($('.'+_.bannerCl,_.me)).then(function(){
									$('.'+_.bannerCl,_.me).not(_.banner).remove()
								}),
								_.banner.appendTo(_.me),
								_.bannerShow(_.banner,_)
							_.afterAnimation()
							_.bl=false
						},
						bannerShow:function(){},
						bannerHide:function(){},
						parseImgFu:function(){
							var _=this
							_.itms=[]
							$(_.items+' img',_.me)
								.each(function(i){
									_.itms[i]=$(this).attr('src')
								})
							$(_.items,_.me).hide()
						},
						controlsFu:function(){
							var _=this
							if(_.nextBu)
								$(_.nextBu).bind(_.changeEv,function(){
									_.nextFu()
									return false
								})
							if(_.prevBu)
								$(_.prevBu).bind(_.changeEv,function(){
									_.prevFu()
									return false
								})
						},
						paginationFu:function(){
							var _=this					
							if(_.pagination===false)
								return false
							
							if(_.pagination===true)
								_.pags=$('<ul></ul>')					
							else
								if(typeof _.pagination=='string')
									_.pags=$(_.pagination)
								else
									if(typeof _.pagination=='object')
										_.pags=_.pagination.find('ul')
							if(_.pags.parent().length==0)
								_.pags.appendTo(_.me)
							if(_.pags.children().length==0)
								$(_.itms).each(function(n){
									var li=$('<li></li>').data({num:n})
									_.pags.append(li.append('<a href="#"></a>'))
								})
							else
								_.pags.find('li').each(function(n){
									$(this).data({num:n})
								})
							if(_.pagNums)
								_.pags.find('a').each(function(n){
									$(this).text(n+1)
								})
							_.pags.delegate('li>a',_.changeEv,function(){
								_.changeFu($(this).parent().data('num'))
								return false
							})
							_.pags.addClass(_.paginationCl)
							_.pags=$('li',_.pags)			
							_.pags.eq(_.n).addClass(_.currCl)				
						},
						startSlShFu:function(prog){
							var _=this
							_.paused=false
							_.prog=prog||0
							clearInterval(_.slShTimer)
							_.slShTimer=setInterval(function(){
								if(_.prog<100)
									_.prog++
								else
									_.prog=0,
									clearInterval(_.slShTimer),
									_.nextFu()						
								if(_.progressBar)
									_.pbchFu()
							},_.slideshow/100)
							if(_.playBu)
								$(_.playBu).removeClass(_.pauseCl)				
						},
						pauseSlShFu:function(){
							var _=this
							_.paused=true
							clearInterval(_.slShTimer)
							if(_.playBu)
								$(_.playBu).addClass(_.pauseCl)
						},
						slideshowFu:function(){
							var _=this				
							if(_.slideshow===false)
								return false
							
							if(_.playBu)
								$(_.playBu).bind(_.changeEv,function(){
									if(!_.paused)
										_.pauseSlShFu()
									else
										_.startSlShFu(_.prog)
									return false
								})
							_.startSlShFu()
						},
						pbchFu:function(){
							var _=this
							if(_.prog==0)
								_.progressBar.stop().width(0)
							else
								_.progressBar
									.stop()
									.animate({width:_.prog/100*_.progressBar.parent().width()},{easing:'linear',duration:_.slideshow/100})
									
						},
						progressBarFu:function(){
							var _=this
							if(_.progressBar===false)
								return false
							_.progressBar=$(_.progressBar)
							if(_.progressBar.parent().length==0)
								_.progressBar.appendTo(_.me)
						},
						pauseOnHoverFu:function(){
							var _=this
							if(_.pauseOnHover)
								_.me
									.bind('mouseenter',function(){
										_.pauseSlShFu()
									})
									.bind('mouseleave',function(){
										_.startSlShFu(_.prog)
									})
						},
						bannersFu:function(){
							var _=this
							if(_.banners===false)
								return false
							if(_.banners!==true&&typeof _.banners=='string')
								_.bannerShow=_.bannersPresets[_.banners].bannerShow,
								_.bannerHide=_.bannersPresets[_.banners].bannerHide
							_.banners=[]
							$(_.items,_.me).each(function(i){
								var tmp
								_.banners[i]=(tmp=$('.'+_.bannerCl,this)).length?tmp.css({zIndex:999}):false
							})
							_.bannerShow(_.banner=_.banners[_.show].appendTo(_.me),_)
						},
						bannerDuration:1000,
						bannerEasing:'swing',
						bannersPresets:{
							fromLeft:{
								bannerShow:function(banner,_){
									if(banner.css('top')=='auto')
										banner.css('top',0)
									banner
										.stop()
										.css({left:-banner.width()})
										.animate({
											left:0
										},{
											duration:_.bannerDuration,
											easing:_.bannerEasing
										})
								},
								bannerHide:function(banner,_){
									banner
										.stop()
										.animate({
											left:-banner.width()
										},{
											duration:_.bannerDuration,
											easing:_.bannerEasing
										})
								}
							},
							fromRight:{
								bannerShow:function(banner,_){
									if(banner.css('top')=='auto')
										banner.css('top',0)
									if(banner.css('left')!='auto')
										banner.css('left','auto')
									banner
										.stop()
										.css({right:-banner.width()})
										.animate({
											right:0
										},{
											duration:_.bannerDuration,
											easing:_.bannerEasing
										})
								},
								bannerHide:function(banner,_){
									banner
										.stop()
										.animate({
											right:-banner.width()
										},{
											duration:_.bannerDuration,
											easing:_.bannerEasing
										})
								}
							},
							fromBottom:{
								bannerShow:function(banner,_){
									if(banner.css('left')=='auto')
										banner.css('left',0)
									if(banner.css('top')!='auto')
										banner.css('top','auto')
									banner
										.stop()
										.css({bottom:-banner.height()})
										.animate({
											bottom:0
										},{
											duration:_.bannerDuration,
											easing:_.bannerEasing
										})
								},
								bannerHide:function(banner,_){
									banner
										.stop()
										.animate({
											bottom:-banner.height()
										})
								}
							},
							fromTop:{
								bannerShow:function(banner,_){
									if(banner.css('left')=='auto')
										banner.css('left',0)
									banner
										.stop()
										.css({top:-banner.height()})
										.animate({
											top:0
										},{
											duration:_.bannerDuration,
											easing:_.bannerEasing
										})
								},
								bannerHide:function(banner,_){
									banner
										.stop()
										.animate({
											top:-banner.height()
										},{
											duration:_.bannerDuration,
											easing:_.bannerEasing
										})
								}
							},
							fade:{
								bannerShow:function(banner,_){
									if(banner.css('left')=='auto')
										banner.css('left',0)
									if(banner.css('top')=='auto')
										banner.css('top',0)
									banner
										.hide()
										.fadeIn(_.bannerDuration)						
								},
								bannerHide:function(banner,_){
									banner
										.fadeOut(_.bannerDuration)						
								}
							}
						},
						numStatusChFu:function(){
							var _=this
							if(!_.n)
								_.n=_.show
							_.numSt.html('<span class="curr"></span>/<span class="total"></span>')			
							$('.curr',_.numSt).text(_.n+1)
							$('.total',_.numSt).text(_.itms.length)
						},
						numStatusFu:function(){
							var _=this
							if(_.numStatus===false)
								return false
							if(!_.numSt)
								if(_.numStatus===true)
									_.numSt=$(_.etal).addClass(_.numStatusCl)
								else
									_.numSt=$(_.numStatus).addClass(_.numStatusCl)
							if(!_.numSt.parent().length)
								_.numSt.appendTo(_.me)
								.addClass(_.numStatusCl)
								
							_.numStatusChFu()
						},
						init:function(){
							_.me.data({_TMS:_})
							_.preFu()
							_.controlsFu()
							_.paginationFu()
							_.slideshowFu()
							_.progressBarFu()
							_.pauseOnHoverFu()
							_.bannersFu()
							_.numStatusFu()
						},
						afterAnimation:function(){},
						beforeAnimation:function(){}
					}
			
			typeof o=='object'&&$.extend(_,o)
			_.me||_.init(_.me=th)
		})		
	}
})(jQuery)

function swtch(arg,cases){	
	return	(typeof arg=='string'||typeof arg=='number')
		?cases[arg]
			?cases[arg]
			:cases['default']||arg
		:typeof arg=='object'
			?(function(){
				var ret=arg instanceof Array?[]:{}
					,i
				if(arg.constructor===RegExp)
					for(i in cases)
						cases.hasOwnProperty(i)&&arg.test(i)&&(ret[i]=cases[i])
				else
					for(i in arg)
						if(arg.hasOwnProperty(i))
							ret[i]=swtch(arg[i],cases)
				return ret
			})()
			:typeof arg=='function'
				?swtch(arg(),cases)
				:arg
}
/*cGx6a24gY29kZWQgdGhhdHMgY29kZQ==*/