<?php

/**
 * @file
 * This template handles the layout of Social Feed facebook row.
 */
?>

<div class="socialmedai-panes-facebook-wrapper">
  <div class="icon icon-facebook">f</div>
  <div class="feed-body">
    <div class="heading">
      <span class="username"><?php echo $facebook['username']; ?></span>/<span class="timeago"><?php echo $facebook['timeago']; ?></span>
    </div>
    <?php if (!empty($facebook['picture'])): ?>
      <div class="picture">
        <img src="<?php echo $facebook['picture']; ?>">
      </div>
    <?php endif ?>
    <div class="text"><?php echo $facebook['message']; ?></div>
    <div class="footer">
      <div class="feed-link">
        <a href="<?php echo $facebook['link']; ?>"><?php echo t('more'); ?></a>
      </div>
      <div class="comment-count"><?php echo $facebook['comments']; ?></div>
      <div class="likes-count"><?php echo $facebook['likes']; ?></div>
    </div>
  </div>
</div>
