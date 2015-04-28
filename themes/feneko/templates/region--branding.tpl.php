<?php

$feneko_title = l('<div class="feneko_logo"><span class="feneko_fenek">Fenek</span><span class="feneko_o">O</span></div>','<front>',array('html' => TRUE));

?><div<?php print $attributes; ?>>
  <div<?php print $content_attributes; ?>>
    <div class="branding-data clearfix">
      <?php if (isset($linked_logo_img)): ?>
      <div class="logo-img">
        <?php print $linked_logo_img; ?>
      </div>
      <?php endif; ?>
      <?php if ($site_name || $site_slogan): ?>
      <?php $class = $site_name_hidden && $site_slogan_hidden ? ' element-invisible' : ''; ?>
      <div class="site-name-slogan<?php print $class; ?>">
        <?php $class = $site_name_hidden && !$site_slogan_hidden ? ' element-invisible' : ''; ?>
        <?php if ($is_front): ?>
        <h1 class="site-title<?php print $class; ?>"><?php print $feneko_title; ?></h1>
        <?php else: ?>
        <h2 class="site-title<?php print $class; ?>"><?php print $feneko_title; ?></h2>
        <?php endif; ?>
        <?php print ($site_slogan_hidden && !$site_name_hidden ? ' element-invisible' : ''); ?>
        <?php if ($site_slogan): ?>
	<div class="site-slogan">
        	<h6 class="<?php print $class; ?>"><?php print $site_slogan; ?></h6>
		<span class='site-slogan-sub'><?php print t('Uw partner voor vliegenramen, vliegendeuren en metaalbewerking'); ?></span>
        </div>
	<?php endif; ?>
      </div>
      <?php endif; ?>
    </div>
    <?php print $content; ?>
  </div>
</div>
