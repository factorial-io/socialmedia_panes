<?php

/**
 * @file
 * This template handles the layout of Social Feed twitter row.
 */
?>

<div class="socialmedia-panes-twitter-wrapper">
  <div class="icon icon-twitter">t</div>
  <div class="feed-body">
    <div class="heading">
      <span class="username"><?php echo $twitter['username']; ?></span>/<span class="timeago"><?php echo $twitter['timeago']; ?></span>
    </div>
    <div class="text"><?php echo $twitter['tweet']; ?></div>
    <div class="footer">
      <div class="feed-link">
        <a href="<?php echo $twitter['link']; ?>"><?php echo t('more'); ?></a>
      </div>
    </div>
  </div>
</div>
